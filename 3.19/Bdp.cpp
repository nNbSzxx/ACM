#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 45;
const int INF = 0x3f3f3f3f;
int main()
{
	int p[MAX], t[MAX];
	int n;
	int dp[MAX][4];
	while (~scanf("%d",&n), n) {
		for (int i = 1; i <= n ; i++) {
			scanf("%d%d",&p[i],&t[i]);
		}
		memset(dp,0x3f,sizeof(dp));
		dp[0][0] = 0;
		p[0] = 0;
		t[0] = 0;
		int flag = 1;
		for (int i = 1; i <= n; i ++) {
			int dis = abs(p[i] - p[i - 1]);
			int dt = t[i] - t[i - 1];
			for (int j = 1; j <= 3; j ++) {
				if (j * dis <= dt) {
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]+dis);
				}
			}
			for (int j = 1; j <= 3; j ++) {
				if(p[i] + p[i-1] * (j+1) <= dt)
					dp[i][1] = min(dp[i][1],dp[i-1][j]+p[i-1]+p[i]);
			}
			if (dp[i][1] == INF && dp[i][2] == INF && dp[i][3] == INF) {
				printf("NG %d\n",i);
				flag = 0;
				break;
			}
		}
		int ans = INF;
		if (flag) {
			for (int i = 1; i <= 3; i ++) {
				ans = min(ans, dp[n][i] + p[n]);
			}
			printf("OK %d\n",ans);
		}
		
	}
}
