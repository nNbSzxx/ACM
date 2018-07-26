#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 10007;
int main()
{
	int dp[25];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 20; i ++) {
		dp[i] = (dp[i-3] + dp[i-2] + dp[i-1]) % MOD;
	}
	int t;
	scanf("%d",&t);
	while (t --) {
		int n,m,ans = 1;
		scanf("%d",&n);
		for (int i = 1; i <= n - 1; i ++) {
			scanf("%d",&m);
			ans = (ans) * (dp[m]) % MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
