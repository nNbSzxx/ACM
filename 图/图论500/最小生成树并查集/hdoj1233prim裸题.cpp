#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 105;
const int INF = 0x3f3f3f3f;
int map[MAX][MAX],n,dis[MAX],visit[MAX];

int main()
{
	while (~scanf("%d",&n), n) {
		int t,u,v;
		//memset(dis,0x3f,sizeof(dis));
		memset(visit,0,sizeof(visit));
		for (int i = 1; i <= n * (n - 1) / 2; i ++) {
			scanf("%d%d%d",&u,&v,&t); 
			map[u][v] = map[v][u] = t; 
		} 
		for (int i = 0; i <= n; i ++) {
			map[i][i] = INF;
		}
		for (int i = 1; i <= n; i ++) {
			dis[i] = map[1][i];
		}
		int minn,loc,ans = 0;
		visit[1] = 1;
		for (int i = 1; i < n; i ++) {
			minn = INF;
			for (int j = 1; j <= n; j ++) {
				if (minn > dis[j] && !visit[j]) {
					minn = dis[j];
					loc = j;
				}
			}
			ans += dis[loc];
			visit[loc] = 1;
			for (int j = 1; j <= n; j ++) {
				if (map[loc][j] != INF) {
					dis[j] = min(dis[j], map[loc][j]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}




