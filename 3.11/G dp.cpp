#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	int c[105],r[105];
	double dp[1005][1005];
	int n,m;
	while (~scanf("%d%d",&n,&m)) {
		int k;
		m ++;
		n ++;
		scanf("%d",&k);
		for (int i = 1; i <= k; i ++) {
			scanf("%d%d",&c[i],&r[i]);
		}
		memset(dp,0,sizeof(dp));
		dp[1][1] = 0;
		for (int i = 2; i <= n; i ++) {
			dp[i][1] = i - 1;
		}
		for (int i = 2; i <= m; i ++) {
			dp[1][i] = i - 1;
		}
		for (int i = 2; i <= n; i ++) {
			for (int j = 2; j <= m; j ++) {
				int flag = 0;
				for (int ii = 1; ii <= k; ii ++) {
					if (c[ii] == i - 1 && r[ii] == j - 1) {
						dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + sqrt(2));
						flag = 1;
						break;
					}
				}
				if (!flag ) {
					dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + 1;
				}
			}
		}
		printf("%.0lf",100 * (dp[n][m]) );
	}
	return 0;
}
