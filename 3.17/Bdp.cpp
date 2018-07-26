#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 105;
int main()
{
	int t;
	int n,m;
	char s[MAX];
	int pos[MAX];
	int dp[MAX][MAX/2+2][MAX];	
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d %s",&n,&m,s+1);
		int cnt = 0;
		m /= 2;
		for (int i = 1; i <= n ; i ++) {
			if (s[i] == '2') {
				pos[++ cnt] = i;
			}
		}
		memset(dp,-1,sizeof(dp));
		dp[0][m][0] = 0;
		for (int i = 1; i <= cnt; i ++) {
			for (int j = 0; j <= m; j ++) {
				for (int k = 0; k <= n; k ++) {
					if (dp[i-1][j][k] == -1) continue;
					for (int p = k + 1; p <= n; p ++) {
						int dis = abs(pos[i] - p);
						if (j < dis) continue;
						if (p + 2 <= n) {
							dp[i][j-dis][p+2] = max(dp[i][j-dis][p+2], dp[i-1][j][k]+1);
						}
						dp[i][j-dis][p] = max(dp[i][j-dis][p],dp[i-1][j][k]);
					}
				}
			}
		}
		int ans=0;
	    for (int j=0;j<=m;j++)
	        for (int k=0;k<=n;k++)
	            ans=max(dp[cnt][j][k],ans);
	    printf("%d\n",ans);
	}
	return 0;
}
