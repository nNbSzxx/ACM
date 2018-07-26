#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
long long dp[100005];
int c[5],d[5],tot;
long long ans;

void dfs(int x, int k,int sum)
{
	if (sum < 0) return ;
	if (x == 5) {
		if (k & 1) {
			ans -= dp[sum];
		} else {
			ans += dp[sum];
		}
		return ;
	}
	dfs(x+1,k,sum);
	dfs(x+1,k+1,sum-(d[x]+1)*c[x]);
	return ;
}

int main()
{
	scanf("%d%d%d%d%d",&c[1],&c[2],&c[3],&c[4],&tot);
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= 4; i ++) {
		for (int j = c[i]; j <= 100000; j ++) {
			dp[j] += dp[j-c[i]];
		}
	}
	for (int i = 1; i <= tot; i ++) {
		for (int j = 1; j <= 4; j ++) {
			scanf("%d",&d[j]);
		}
		int m;
		scanf("%d",&m);
		ans = 0;
		dfs(1,0,m);
		printf("%lld\n",ans);
	}
	return 0;
}
