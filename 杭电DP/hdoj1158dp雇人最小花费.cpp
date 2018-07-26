#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int h,s,f;
	int m[13];
	int dp[13][10010];
	while (scanf("%d",&n), n) {
		scanf("%d%d%d",&h,&s,&f);
		int p = 0;
		for (int i = 1; i <= n;  i ++) {
			scanf("%d",&m[i]);
			if (m[i] > p) p = m[i];
		}
		memset(dp,0x3f,sizeof(dp));
		for (int i = m[1]; i <= p; i ++) {
			dp[1][i] = i * (h + s);
		}
		for (int i = 2; i <= n; i ++) {
			for (int j = m[i]; j <= p; j ++) {
				dp[i][j] += j * s;
				for (int k = m[i - 1]; k <= p; k ++){
					if (k <= j)
						dp[i][j] = min(dp[i][j], dp[i-1][k] + (j * s) + (j - k) * h);
					else
						dp[i][j] = min(dp[i][j], dp[i-1][k] + (j * s) + (k - j) * f);
				}	
			}
		}
		int ans = 0x3f3f3f3f;
		for (int i = m[n]; i <= p; i ++) {
			if (dp[n][i] < ans)
				ans = dp[n][i];
		}
		printf("%d\n",ans);
	}
	return 0;
} 
