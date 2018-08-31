#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 10;
const int INF = 0x3f3f3f3f;

int dis[MAXN + 3][MAXN + 3];
int pow3[MAXN + 3];
int dp[60000][MAXN];
int tri[60000][MAXN];
int n, m;

void init()
{
	pow3[0] = 1;
	for (int i = 1; i <= MAXN; i ++) {
		pow3[i] = pow3[i - 1] * 3;
//		printf("%d %d\n", i, pow3[i]);
	}
	memset(tri, 0, sizeof tri);
	for (int i = 0; i < pow3[MAXN]; i ++) {
		int t = i;
		for (int j = 0; j < MAXN && t; j ++) {
			tri[i][j] = t % 3;
			t /= 3;
		}
	}
}

int main()
{
	init();
	while (~scanf("%d%d", &n, &m)) {
		memset(dis, 0x3f, sizeof dis);
		for (int i = 1; i <= m; i ++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			-- u; -- v;
			dis[u][v] = dis[v][u] = min(w, dis[u][v]);
		}
		int ans = INF;
		memset(dp, 0x3f, sizeof dp);
		for (int i = 0; i < n; i ++) {
			dp[pow3[i]][i] = 0;
		}
		for (int mask = 1; mask < pow3[n]; mask ++) {
			int flag = 1;
			for (int u = 0; u < n; u ++) {
				if (tri[mask][u] < 1 || tri[mask][u] > 2) {
					flag = 0;
				}
				if (dp[mask][u] >= INF) {
					continue;
				}
				for (int v = 0; v < n; v ++) {
					if (tri[mask][v] >= 2) {
						continue;
					}
					dp[mask + pow3[v]][v] = min(dp[mask + pow3[v]][v], dp[mask][u] + dis[u][v]);
				}
			}
			if (flag) {
				for (int u = 0; u < n; u ++) {
					ans = min(ans, dp[mask][u]);
				}
			}
		}
		if (ans != INF)
			printf("%d\n", ans);
		else 
			puts("-1");
	}
	
	return 0;
}





