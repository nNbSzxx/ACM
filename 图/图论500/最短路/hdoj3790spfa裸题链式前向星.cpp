#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1005;
const int M = 100005;
const int INF = 0x3f3f3f3f;
int n, m, cnt, s, t;
int vis[N], dis[N], head[N], cost[N];
struct E{
	int v, w, c, nt;
}e[M * 2];
void init(void)
{
	memset(head, 0, sizeof(head));
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	memset(cost, 0x3f, sizeof(cost));
	cnt = 1;
}
void add(int u, int v, int w, int c)
{
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].c = c;
	e[cnt].nt = head[u];
	head[u] = cnt;
	++ cnt;
}
void spfa(void)
{
	vis[s] = 1;
	dis[s] = 0;
	cost[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int now = q.front(); q.pop(); vis[now] = 0;
		for (int i = head[now]; i; i = e[i].nt) {
			if (dis[e[i].v] > dis[now] + e[i].w) {
				dis[e[i].v] = dis[now] + e[i].w;
				cost[e[i].v] = cost[now] + e[i].c;
				q.push(e[i].v);
				vis[e[i].v] = 1;
			}
			if (dis[e[i].v] == dis[now] + e[i].w && cost[e[i].v] > cost[now] + e[i].c) {
				dis[e[i].v] = dis[now] + e[i].w;
				cost[e[i].v] = cost[now] + e[i].c;
				q.push(e[i].v);
				vis[e[i].v] = 1;
			}
		}
	}
}
int main()
{
	while (~scanf("%d%d",&n,&m), n || m) {
		init();
		int u, v, w, c;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d%d", &u, &v, &w, &c);
			add(u,v,w,c);
			add(v,u,w,c);
		}
		scanf("%d%d",&s,&t);
		spfa();
		printf("%d %d\n",dis[t], cost[t]);
	}
	return 0;
}



