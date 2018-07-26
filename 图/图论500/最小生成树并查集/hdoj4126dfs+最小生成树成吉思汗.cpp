#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 3005;
const int M = (N - 5) * (N - 5) + 5;
int map[N][N], pick[N][N], father[N], dis[N][N];
vector<int> e[N];
int n,m,q;
struct E{
	int u,v,w;
} edge[M];
bool cmp(const E& e1, const E& e2)
{
	return e1.w < e2.w;
}
int find(int x)
{
	while (x != father[x]) {
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}
void init(void)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(map, 0x3f, sizeof(map));
	memset(pick, 0, sizeof(pick));
	for (int i = 0; i < n; i ++) {
		e[i].clear();
		father[i] = i;
	}
}
// dfs(root, u, pre)表示 pre到u的边断开时，以root为pre这棵子树的出口与u的子树相连的最短路径 
int dfs(int root, int u, int pre)
{
	int ret = INF;
	for (int i = 0; i < e[u].size(); i ++) {
		int v = e[u][i];
		if (v != pre) {
			int t = dfs(root, v, u);
			ret = min(ret, t);
			dis[u][v] = dis[v][u] = min(dis[u][v], t);
		}
	}
	if (pre != root) {
		ret = min(ret, map[root][u]);
	}
	return ret;
}
int main()
{
	while (~scanf("%d%d",&n,&m), n || m) {
		init();
		int u, v, w;
		for (int i = 0; i < m; i ++) {
			scanf("%d%d%d",&u,&v,&w);
			map[u][v] = map[v][u] = w;
			edge[i].u = u;
			edge[i].v = v;
			edge[i].w = w;
		}
		sort(edge, edge + m, cmp);
		int cnt = 0, x, y, ret = 0;
		for (int i = 0; i < m, cnt < n - 1; i ++) {
			x = find(edge[i].u);
			y = find(edge[i].v);
			if (x != y) {
				father[x] = y;
				++ cnt;
				e[edge[i].u].push_back(edge[i].v);
				e[edge[i].v].push_back(edge[i].u);
				pick[edge[i].u][edge[i].v] = pick[edge[i].v][edge[i].u] = 1;
				ret += edge[i].w;
			}
		}
//		printf("%d\n", ret);
		for (int i = 0; i < n; i ++) {
			dfs(i, i, -1);		
		}
		scanf("%d",&q);
		double sum = 0;
		for (int i = 1 ; i <= q; i ++) {
			scanf("%d%d%d",&u,&v,&w);
			if (!pick[u][v]) {
				sum += ret;
			} else {
				sum += ret - map[u][v] + min(w, dis[u][v]); 
			}
		}
		printf("%.4lf\n", 1.0 * sum / q);
	}
	return 0;
}

