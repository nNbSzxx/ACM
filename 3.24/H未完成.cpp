#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 7005;
int dfs(int now, int step)
{
	if (now == 1) {
		return dp[now][step];
	}
	if (step == 1)
}
int main()
{
	int dp[7005][2];
	int n,s1[MAX],s2[MAX],n1,n2;
	scanf("%d%d",&n,&n1);
	for (int i = 1; i <= n1; i ++) {
		scanf("%d",&s1[i]);
	}
	scanf("%d",&n2);
	for (int i = 1; i <= n2; i ++) {
		scanf("%d",&s2[i]);
	}
	memset(dp,-1,sizeof(dp));
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 1; i <= n; i ++) {
		
	}
}
