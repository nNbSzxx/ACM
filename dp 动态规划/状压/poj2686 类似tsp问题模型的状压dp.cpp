#include <iostream>
#include <algorithm>
#include <cstring> 
#include <cstdio>
using namespace std;
const int MAXN = 8;
const int MAXM = 33;
const double INF = 0x3f3f3f3f;

int n, m, p, s, d;
int h[MAXN + 5];
int dis[MAXM][MAXM];
double dp[(1 << MAXN) + 5][MAXM];

int main()
{
	while (~scanf("%d", &n), n) {
		scanf("%d%d%d%d", &m, &p, &s, &d);
		for (int i = 0; i < n; i ++) {
			scanf("%d", &h[i]);
		}
		int u, v, w;
		memset(dis, 0x3f, sizeof dis);
		for (int i = 1; i <= p; i ++) {
			scanf("%d%d%d", &u, &v, &w);
			dis[u][v] = dis[v][u] = w;
		}
		for (int i = 0; i < (1 << n); i ++) {
			for (int j = 1; j <= m; j ++) {
				dp[i][j] = INF;
			}
		}
		dp[(1 << n) - 1][s] = 0;
		for (int mask = (1 << n) - 1; mask >= 0; mask --) {
			for (int i = 0; i < n; i ++) {
				if ((mask >> i) & 1) {
					for (int u = 1; u <= m; u ++) {
						if (dp[mask][u] + 0.1 < INF) {
							for (int v = 1; v <= m; v ++) {
								if (dis[u][v] + 0.1 < INF) {
									dp[mask ^ (1 << i)][v] = 
										min(dp[mask ^ (1 << i)][v],
										    dp[mask][u] + 1.0 * dis[u][v] / h[i]);
								}
							}
						}
					}
				}
			}
		}
		double ans = INF;
		for (int i = 0; i < (1 << n); i ++) {
			ans = min(ans, dp[i][d]);
		}
		if (ans + 0.1 < INF) {
			printf("%.6f\n", ans);
		} else {
			puts("Impossible");
		}
	}
	return 0;
}



