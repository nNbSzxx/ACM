#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 20;
const int INF = 0x3f3f3f3f;
int n, m, node[MAX];
int map[MAX][MAX];
int pick[MAX], a[MAX], cost[MAX], vis[MAX];
double ans;

void init(void)
{
	memset(pick, 0, sizeof(pick));
	memset(a, 0, sizeof(a));
	ans = 1e19;
}
double prim(void);
void dfs(int x, int cnt)
{
	if (cnt > m) {
		double b = prim();
//		printf("%lf\n", b);
//		for (int i = 1; i <= n; i ++) {
//			if (pick[i]) {
//				printf("%d ", i);
//			}
//		}
//		printf("\n");
		if (b < ans) {
			ans = b;
			memcpy(a, pick, sizeof(a));
		}
		return ;
	}
	if (x > n) return ;
	pick[x] = 1;
	dfs(x + 1, cnt + 1);
	pick[x] = 0;
	dfs(x + 1, cnt);
	return ;
}
double prim(void)
{
	int s;
	int sumnode = 0, sumedge = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i ++) {
		if (pick[i]) {
			s = i;
			break;
		}
	}
	vis[s] = 1;
	for (int i = 1; i <= n; i ++) {
		if (pick[i]) {
			cost[i] = map[s][i];
			sumnode += node[i];
		}
	}
	for (int i = 1; i <= m - 1; i ++) {
		int minn = INF, minid;
		for (int j = 1; j <= n; j ++) {
			if (pick[j] && !vis[j] && cost[j] < minn) {
				minn = cost[j];
				minid = j;
			}
		}
		sumedge += minn;
		vis[minid] = 1;
		for (int j = 1; j <= n; j ++) {
			if (pick[j] && !vis[j])
				cost[j] = min(cost[j], map[minid][j]);
		}
	}
	return 1.0 * sumedge / sumnode;
}
int main()
{
	while (~scanf("%d%d", &n, &m), m || n) {
		init();
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&node[i]);
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				scanf("%d",&map[i][j]);
			}
		}
		dfs(1, 1);
		int i;
		for (i = 1; i <= n; i ++) {
			if (a[i]) {
				printf("%d", i);
				break;
			}
		}
		for (i = i + 1; i <= n; i ++) {
			if (a[i]) {
				printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
