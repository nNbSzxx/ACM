#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1005;
const int INF = 0x3f3f3f3f;
int vis[MAX], dis[MAX];
int n, m;
struct E{
	int v, w;
	E(int vv, int ww) {
		v = vv;
		w = ww;
	}
};
vector<E> edge[MAX];
int spfa()
{
	vis[1] = 1;
	dis[1] = 0;
	queue<int> q;
	q.push(1);
	
	while (!q.empty()) {
		int now = q.front(); q.pop(); vis[now] = 0;
		for (int i = 0; i < edge[now].size(); i ++) {
			if (edge[now][i].w + dis[now] < dis[edge[now][i].v]) {
				q.push(edge[now][i].v);
				dis[edge[now][i].v] = edge[now][i].w + dis[now];
				vis[edge[now][i].v] = 1;
			}
		}
	}
	return dis[n];
}
void init(void)
{
	for (int i = 1; i <= n; i ++) {
		edge[i].clear();
	}
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
}
int main()
{
	while (~scanf("%d%d",&n,&m), n || m) {
		init();
		int u, v, w;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d",&u,&v,&w);
			edge[u].push_back(E(v,w));
			edge[v].push_back(E(u,w));
		}
		printf("%d\n",spfa());
	}
	return 0;
}
