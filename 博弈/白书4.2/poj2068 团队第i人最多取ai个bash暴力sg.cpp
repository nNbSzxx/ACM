#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 25;
int n, s;
int maxx[MAX];
int dp[MAX][(1 << 13) + 10];

int dfs(int id, int rem)
{
	if (id >= 2 * n) {
		id -= 2 * n;
	}
	if (dp[id][rem] != -1) {
		return dp[id][rem];
	}
	if (rem == 0) {
		return dp[id][rem] = 1;
	}
	int ret = 1;
	for (int i = 1; i <= maxx[id]; i ++) {
		if (i > rem) {
			break;
		}
		ret &= dfs(id + 1, rem - i);
	}
	return dp[id][rem] = !ret;
}

int main()
{
	while (~scanf("%d", &n), n) {
		scanf("%d", &s);
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n * 2; i ++) {
			scanf("%d", &maxx[i]);
		}
		if (dfs(0, s)) {
			puts("1");
		} else {
			puts("0");
		}
	}
	return 0;
}
