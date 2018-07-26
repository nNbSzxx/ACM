#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX= 100010;
int dp[MAX];
int n,k;

int dfs(int x)
{
	if (dp[x] != -1 ) {
		return dp[x];
	}
	if (k == x) {
		dp[k] = 0;
	}
	int m = 0x3f3f3f3f;
	if (x - 1 >= 0)
		m = min(m, dfs(x - 1));
	if (x + 1 <= 100000)
		m = min(m, dfs(x + 1));
	if (!(x & 1) && (x != 0)) {
		m = min(m,dfs(x >> 1));
	}
	if ((x << 1) <= 100000)
		m = min(m,dfs(x << 1));
	return dp[x] = m + 1;
}

int main()
{
	while (~scanf("%d%d",&n,&k)) {
		memset(dp,-1,sizeof(dp));
		dfs(k);
		printf("%d\n",dp[n]);
	}
	return 0;
}
