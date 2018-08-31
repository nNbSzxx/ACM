#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2010;
int n;
int dp[MAX]; 

int dfs(int x)
{
	if (x < 0) {
		return 0;
	}
	if (dp[x] != -1) {
		return dp[x];
	}
	if (x <= 3 && x > 0) {
		return dp[x] = 1;
	}
	int vis[MAX];
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= x; i ++) {
		vis[dfs(i - 3) ^ dfs(x - i - 2)] = 1;
	}
	for (int i = 0; ; i ++) {
		if (!vis[i]) {
			return dp[x] = i;
		}
	}
}

int main()
{
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	while (~scanf("%d", &n)) {
		if (dfs(n)) {
			puts("1");
		} else {
			puts("2");
		}
	}
	
	return 0;
}
 
