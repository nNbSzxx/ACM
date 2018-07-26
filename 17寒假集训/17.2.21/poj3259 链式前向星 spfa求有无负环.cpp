#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 6000;

int n,m,w;

struct T
{
	int to,w,nt;
};
T edge[MAX];
int cnt[510],head[510],visit[510];
int cnte;
queue<int> q;
void add(int u, int v , int w)
{
	edge[cnte].to = v;
	edge[cnte].w = w;
	edge[cnte].nt = head[u];
	head[u] = cnte;
	cnte ++;
}

int spfa(void)
{

	int dis[510];
	for (int i = 0; i <= n; i ++) {
		dis[i] = 22222;
	}
	dis[1] = 0;
	visit[1] = 1;
	cnt[1] ++;
	q.push(1);
	while(!q.empty()) {
		int now = q.front(); q.pop();
		visit[now] = 0;
		for (int i = head[now]; i; i = edge[i].nt) {
			if (dis[now] + edge[i].w < dis[edge[i].to]) {
				dis[edge[i].to] = dis[now] + edge[i].w;
				if (!visit[edge[i].to]) {
				
					cnt[edge[i].to] ++;
					if (cnt[edge[i].to] >= n) return 1;
					q.push(edge[i].to);
					visit[edge[i].to] = 1;
				}
				
			}
		}
		
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	
	int f;
	scanf("%d",&f);
	while(f --) {
		scanf("%d%d%d",&n,&m,&w);
		cnte = 1;
		memset(cnt,0,sizeof(cnt));
		memset(visit,0,sizeof(visit));
		memset(head,0,sizeof(head));
		memset(edge,0,sizeof(edge)); 
		int a,b,v;
		for (int i = 0; i < m; i ++) {
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
			add(b,a,v);
		}
		for (int i = 0; i < w; i ++) {
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,-v);
		}
		if (spfa() ) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
