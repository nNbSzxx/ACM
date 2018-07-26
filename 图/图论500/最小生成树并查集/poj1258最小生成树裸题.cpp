#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 105;
const int  INF = 0x3f3f3f3f;
int map[MAX][MAX], n, dis[MAX], vis[MAX];
int prim(void)
{
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i ++) {
		dis[i] = map[1][i];
	}
	vis[1] = 1;
	for (int i = 1; i <= n - 1; i ++) {
		int minn = INF, minid;
		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && dis[j] < minn) {
				minn = dis[j];
				minid = j;
			}
		}
		vis[minid] = 1;
		ans += minn;
		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && dis[j] > map[minid][j]) {
				dis[j] = map[minid][j];
			}
		}
	}
	return ans;
}
int main()
{
	while (~scanf("%d",&n)) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				scanf("%d",&map[i][j]);
			}
		}
		for (int i = 1; i <= n; i ++) {
			map[i][i] = INF;
		}
		int ans = prim();
		printf("%d\n", ans);
	}
	return 0;
}
