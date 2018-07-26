#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int const MAXN = 110;
const int INF = 0x01010101;
int n,m;
int map[MAXN][MAXN],dis[MAXN][MAXN];

inline int min(int a, int b)
{
	return a>b?b:a;
}

int main()
{
	while (~scanf("%d%d",&n,&m)) {
		memset(map,0x01,sizeof(map));
		memset(dis,0x01,sizeof(dis));
		int x,y,w;
		for (int i = 0; i < m; i ++) {
			scanf("%d%d%d",&x,&y,&w);
			if (map[x][y] > w)
				map[x][y] = map[y][x] = dis[x][y] = dis[y][x] = w;
		}
		int ans = INF;
		for (int k = 1; k <= n; k ++) {
			for (int i = 1; i < k; i ++) {
				for (int j = i + 1; j < k; j ++) {
					ans = min(ans,dis[i][j]+map[i][k]+map[k][j]);
				}
			}

			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= n ; j ++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}

		if (ans != INF)
			printf("%d\n",ans);
		else 
			printf("It's impossible.\n");
	}
	
	return 0;
}
