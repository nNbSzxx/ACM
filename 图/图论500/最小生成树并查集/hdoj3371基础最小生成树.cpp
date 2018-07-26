#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int map[505][505];
int dis[505];
int vis[505], temp[505];
	int t,n,m,k;
	
int prim(void)
{
	memset(vis,0,sizeof(vis));
	vis[1] = 1;
	for (int i = 1; i <= n; i ++) {
		dis[i] = map[1][i];
	}
	int ans = 0;
	for (int i = 1; i < n; i ++) {
		int minn = INF, minid = 0;
		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && minn > dis[j]) {
				minn = dis[j];
				minid = j;
			}
		}
		if (minid == 0) return -1;
		vis[minid] = 1;
		ans += minn;
		for (int j = 1; j <= n; j ++) {
			if (!vis[j]) {
				dis[j] = min(dis[j], map[minid][j]);
			}
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d%d",&n,&m,&k);
		memset(map,0x3f,sizeof(map));
		
		int u,v,w;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d",&u,&v,&w);
			if (map[u][v] > w) {
				map[u][v] = map[v][u] = w;
			}
		}
		int s,t1;
		for (int i = 1; i <= k; i ++) {
			scanf("%d",&s);
			for (int j = 1; j <= s ; j ++) {
				scanf("%d",&temp[j]);
				for (int jj = 1; jj < j; jj ++) {
					map[temp[j]][temp[jj]] = map[temp[jj]][temp[j]] = 0;
				} 
			}
		}
		
		printf("%d\n",prim());
	}
	return 0;
}




