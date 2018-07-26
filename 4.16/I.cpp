#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
struct E {
	int v,w,nt;
}e[MAX * 2];
int n, m, head[MAX], cnt, vis[MAX], dis[MAX], ans[MAX];

void add(int u, int v, int w)
{
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].nt = head[u];
	head[u] = cnt ++;
	return ; 
}

void bfs()
{
	queue<int> q;
	q.push(n);
	memset(vis,0,sizeof(vis));
	vis[n] = 1;
	dis[n] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = head[now]; i; i = e[i].nt) {
			if (!vis[e[i].v]) {
				q.push(e[i].v);
				dis[e[i].v] = dis[now] + 1;
				vis[e[i].v] = 1;
			}
		}
	}
	return ;
}
void bfss()
{
	queue<int> q;
	vector<int> v;
	q.push(1);
	memset(vis,0,sizeof(vis));
	vis[1] = 1;
	while (!vis[n]) {
		int minn = INF; v.clear(); int now;
		while (!q.empty()) {
			now = q.front(); q.pop();
			for (int i = head[now]; i; i = e[i].nt) {
				if (!vis[e[i].v] && dis[now] == dis[e[i].v] + 1) {
					if (e[i].w < minn) {
						minn = e[i].w;
						v.clear();
						v.push_back(e[i].v);
					}
					if (e[i].w == minn) {
						v.push_back(e[i].v);
					}
				}
			}
		}
		ans[dis[now]] = minn;
		for (int i = 0; i < v.size(); i ++) {
			if (!vis[v[i]])
				q.push(v[i]), v[i] = 1;
		}
	}
	return ;
}

int main()
{
	while (~scanf("%d%d",&n,&m)) {
		memset(head, 0 ,sizeof(head));
		cnt = 1;
		int u,v,w;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d",&u,&v,&w);
			if (u != v) {
				add (u,v,w);
				add (v,u,w);
			}	
		}
		bfs();
		bfss();
		printf("%d\n",dis[1]);
		printf("%d",ans[dis[1]]);
		for (int i = dis[1] - 1; i >= 1; i --) {
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
} 
