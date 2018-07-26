#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 1005;
const int INF = 0x3F3F3F3F;
int tp,s,d;
int dis[MAX];
int visit[MAX] ;
int matr[MAX][MAX];

int spfa (int start)
{
	memset(visit,0,sizeof(visit));
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	memset(dis,0x3F,sizeof(dis));
	dis[start] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop(); 
		for (int i = 0;i < MAX; i ++) {
			if (matr[now][i] != INF)	
				if (dis[i] > dis[now] + matr[now][i]) {
					dis[i] = dis[now] + matr[now][i];
					if (!visit[i]) {
						q.push(i);
						visit[i] = 1;
					}
				}
		}
		visit[now] = 0;
	}
	int min = INF;
	for (int i = 0; i < d; i ++) {
		int temp;
		scanf("%d",&temp);
		if (min > dis[temp] ) {
			min = dis[temp];
		}
	}
	return min;
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d%d",&tp,&s,&d)) {
		memset(matr,INF,sizeof(matr));
	
		for (int i = 0; i < tp; i ++) {
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			if (matr[a][b] > w) 
				matr[b][a] = matr[a][b] = w;
		}
		for (int i = 0; i < s; i ++) {
			int temp;
			scanf("%d",&temp);
			matr[0][temp] = matr[temp][0] = 0;
		}
		printf("%d\n",spfa(0));

	}

	return 0;
}
