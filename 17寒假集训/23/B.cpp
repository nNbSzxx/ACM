#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1005;
const int MAXM = 100005;
const int INF = 0x3f3f3f3f;

int n,m;
int cost[MAXN][MAXN];
int map[MAXN][MAXN];
int dis[MAXN];
int c[MAXN];
int visit[MAXN];

void spfa(int start)
{
	dis[start] = 0;
	c[start] = 0;
	visit[start] = 1;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int now = q.front(); q.pop(); visit[now] = 0;
		for (int i = 1; i <= n; i ++) {
			if (dis[i] > dis[now] + map[i][now] || dis[i] == dis[now] + map[i][now] && c[i] > c[now] + cost[i][now]) {
				dis[i] = dis[now] + map[i][now];
				c[i] = c[now] + cost[i][now];
				if (!visit[i]) {
					q.push(i);
					visit[i] = 1;
				}
			}
			
		}
	}
}

int main()
{
	while(~	scanf("%d%d",&n,&m), m || n) {
		memset(map,0x3f,sizeof(map));
		memset(cost,0x3f,sizeof(cost));
		memset(visit,0,sizeof(visit));
		memset(dis,0x3f,sizeof(dis));
		memset(c,0x3f,sizeof(c));
		for (int i = 1; i <= m; i ++) {
			int x,y,d,p;
			scanf("%d%d%d%d",&x,&y,&d,&p);
			if (map[x][y] > d || (map[x][y] == d && cost[x][y] > p)) {
				map[x][y] = map[y][x] = d;
				cost[x][y] = cost[y][x] = p;
			}
		}
		
		int u,v;
		scanf("%d%d",&u,&v);
		spfa(u);
		printf("%d %d\n",dis[v],c[v]);
		
	}
		
	
	
	return 0;
}
