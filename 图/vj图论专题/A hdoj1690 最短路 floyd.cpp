#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 105;
const int MAXM = 505;
const __int64 INF = 1e15 + 5;

inline __int64 Min(__int64 a, __int64 b)
{
	return a > b ? b : a;
}

int main() 
{
	int t;
	scanf("%d",&t);
	__int64 m,n,l1,l2,l3,l4,c1,c2,c3,c4;
	__int64 dis[MAXN][MAXN];
	__int64 pos[MAXN];
	int tc = 1;
	while (t --) {
		memset(dis,0,sizeof(dis));
		memset(pos,0,sizeof(pos));
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&l1,&l2,&l3,&l4,&c1,&c2,&c3,&c4);
		scanf("%I64d%I64d",&n,&m);
		for ( int i = 1; i <= n; i ++) {
			scanf("%I64d",&pos[i]);
			for (int j = 1; j < i; j ++) {
				__int64 d = abs(pos[i] - pos[j]);
				if (0 < d && d <= l1) dis[i][j] = dis[j][i] = c1;
				if (l1 < d && d <= l2) dis[i][j] = dis[j][i] = c2;
				if (l2 < d && d <= l3) dis[i][j] = dis[j][i] = c3;
				if (l3 < d && d <= l4) dis[i][j] = dis[j][i] = c4;
				if (d > l4) dis[i][j]= dis[j][i] = INF;
			}
		}
		for (int k = 1; k <= n; k ++) {
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= n; j ++) {
					dis[i][j] = Min(dis[i][j],dis[i][k] + dis[k][j]);
				}
			}
		}
		int temp;
		printf("Case %d:\n",tc ++);
		for (int i = 0; i < m; i ++) {
			int u,v;
			scanf("%d%d",&u,&v);
			if (dis[u][v] != INF)
				printf("The minimum cost between station %d and station %d is %I64d.\n", u, v, dis[u][v]);
			else 
				printf("Station %d and station %d are not attainable.\n",u,v);
		}
	}	
	return 0;
} 
