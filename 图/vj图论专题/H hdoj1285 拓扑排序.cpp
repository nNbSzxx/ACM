#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 505;
const int INF = 0x3f3f3f3f;

int n,m;
int map[MAX][MAX];
int degree[MAX];
int visit[MAX];
queue<int> q;

void tsort(void)
{
	while (!q.empty()) q.pop();
	memset(visit,0,sizeof(visit));
	for (int j = 1; j <= n; j ++) {
		if (degree[j] == 0) {
			q.push(j);
			visit[j] = 1;
			printf("%d",j);
			break;
		}
	}
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 1; i <= n; i ++) {
			if (map[now][i]) {
				degree[i] --;
			}
		}
		for (int i = 1; i <= n; i ++) {
			if (degree[i] == 0 && !visit[i]) {
				q.push(i);
				visit[i] = 1;
				printf(" %d",i);
				break;
			}
		}
		
	}
	printf("\n");
}

int main()
{
	while (~scanf("%d%d",&n,&m) ) {
		memset(map,0,sizeof(map));
		memset(degree,0,sizeof(degree));
		for (int i = 1; i <= m; i ++) {
			int x,y;
			scanf("%d%d",&x,&y);
			if (map[x][y]) ; else {map[x][y] = 1;
			degree[y] ++;
			}
			
		}
		tsort();
	}
}
