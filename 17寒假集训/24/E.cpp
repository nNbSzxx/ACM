#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX= 1005;
const int INF = 0x3f3f3f3f;

int map[MAX][MAX];
int dis1[MAX];
int dis2[MAX];
int visit[MAX];

int spfa (int start)
{
	memset(visit,0,sizeof(visit));
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	memset(dis1,0x3F,sizeof(dis1));
	dis1[start] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop(); 
		for (int i = 0;i < MAX; i ++) {
			if (map[now][i] != INF)	
				if (dis1[i] > dis1[now] + map[now][i]) {
					dis1[i] = dis1[now] + map[now][i];
					if (!visit[i]) {
						q.push(i);
						visit[i] = 1;
					}
				}
		}
		visit[now] = 0;
	}
	
	memset(visit,0,sizeof(visit));
	q.push(start);
	visit[start] = 1;
	memset(dis2,0x3F,sizeof(dis2));
	dis2[start] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop(); 
		for (int i = 0;i < MAX; i ++) {
			if (map[i][now] != INF)	
				if (dis2[i] > dis2[now] + map[i][now]) {
					dis2[i] = dis2[now] + map[i][now];
					if (!visit[i]) {
						q.push(i);
						visit[i] = 1;
					}
				}
		}
		visit[now] = 0;
	}
	
}

int main()
{
	int n,m,x;
	while (~scanf("%d%d%d",&n,&m,&x)) {
		memset(map,0x3f,sizeof(map));
		for (int i = 0; i < m; i ++) {
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			if (map[u][v] > c)
				map[u][v] = c;
		}
		int max= -INF;
		spfa(x);
		for (int i = 1; i <= n; i ++) {
			if (max < dis1[i] + dis2[i]) {
				max = dis1[i] + dis2[i];
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
