//while(true) RP++;
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 105;

int main()
{
	int dp[105][MAX];
	int a[MAX];
	int m,n;
	while (~scanf("%d%d",&m,&n)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
		}
		
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= m; i ++) {
			dp[i][i] = dp[i - 1][i - 1] + a[i];
			for (int j = i; j <= n; j ++) {
				dp[i][j] = dp[i][j-1] + a[j];
				for (int k = i - 1; k <= j - 1; k ++) {
					dp[i][j] = max(dp[i-1][k] + a[j], dp[i][j]);
				}
			}
		}
		
		printf("%d\n",dp[m][n]);
	}
	
	return 0;
}

