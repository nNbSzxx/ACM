#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 205;

int main()
{
	int dp[35][MAX];
	int rest[MAX];
	int dis[MAX][MAX]; 
	int n,m;
	int tc = 0;
	while (scanf("%d%d",&m,&n), n || m) {
		memset(dp,0x3f,sizeof(dp));
		memset(dis,0,sizeof(dis));
		for (int i = 1; i <= m; i ++) {
			scanf("%d", &rest[i]);
		}
		for (int i = 1; i <= m; i ++) {
			for (int j = i;j <= m; j ++) {
				int mid = (i + j) / 2;
				for (int k = i; k <= j;k ++)
					dis[i][j] += abs(rest[k] - rest[mid]);
			}
		}
		for (int i = 1; i <= m; i ++) {
			dp[1][i] = dis[1][i];
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = i; j <= m; j ++) {
				if (i == j) {
					dp[i][j] = 0;
					continue ;
				}
				for (int k = i - 1; k < j; k ++) {
					dp[i][j] = min(dp[i][j], dp[i-1][k] + dis[k+1][j]);
				}
			}
		}
		printf("Chain %d\nTotal distance sum = ", ++ tc);
		printf("%d\n\n",dp[n][m]);
	}
}
