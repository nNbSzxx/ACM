#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int MAX = 1005;
const double INF = 1e10;
double map[MAX][MAX], xx[MAX], yy[MAX];
int n, p[MAX], vis[MAX], fu, fv, pmax;
struct edge {
	int u, v;
	double w;
} dis[MAX], e[MAX];
vector<int> ve[MAX];
void init(void)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i ++)
		ve[i].clear();
	pmax = 0;
}
inline double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int dfs(int x)
{
//	printf("%d\n", x);
	vis[x] = 1;
	if (p[x] > pmax) pmax = p[x];
	for (int i = 0; i < ve[x].size(); i ++) {
		if (!vis[ve[x][i]] && !(fu == x && fv == ve[x][i] || fu == ve[x][i] && fv == x)) {
			dfs(ve[x][i]);
		}
	}
}
double prim(void)
{
	double ret = 0;
	vis[1] = 1;
	for (int i = 1; i <= n; i ++) {
		dis[i].w = map[1][i];
		dis[i].u = 1;
		dis[i].v = i;
	}
	for (int i = 1; i <= n - 1; i ++) {
		double min = INF;
		int minid;
		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && dis[j].w < min) {
				min = dis[j].w;
				minid = j;
			}
		}
		vis[minid] = 1;
		ret += min;
		e[i] = dis[minid];
		ve[e[i].u].push_back(e[i].v);
		ve[e[i].v].push_back(e[i].u);
		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && dis[j].w > map[minid][j]) {
				dis[j].w = map[minid][j];
				dis[j].u = minid;
			}
		}
	}
	return ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		init();
		scanf("%d",&n);
		for (int i = 1; i <= n; i ++) {
			scanf("%lf%lf%d",&xx[i], &yy[i], &p[i]);
			for (int j = 1; j < i; j ++) {
				map[i][j] = map[j][i] = dist(xx[i], yy[i], xx[j], yy[j]);
			}
			map[i][i] = INF;
		}
		double len = prim();
		double ans = -INF;
		int pp;
		for (int i = 1; i <= n - 1; i ++) {
			memset(vis, 0, sizeof(vis));
			pmax = 0;
			fu = e[i].u;
			fv = e[i].v;
			dfs(fu);
			pp = 0;
			pp += pmax;
//			puts("");
			memset(vis, 0, sizeof(vis));
			pmax = 0;
			dfs(fv);
//			puts("");
			pp += pmax;
			ans = max(ans, pp / (len - e[i].w));
		}
		printf("%.2lf\n", ans);
	}
	
	return 0;
}

