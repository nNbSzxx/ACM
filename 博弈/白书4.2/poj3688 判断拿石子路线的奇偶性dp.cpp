#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 1e5 + 10;

int dp[MAXM][2];
int a[MAXN];
int n, m;

int main()
{
	while (~scanf("%d%d", &n, &m), n || m) {
		int sum = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		m = min(m, sum);
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 1; i <= n; i ++) {
			for (int j = m; j >= a[i]; -- j) {
				dp[j][0] |= dp[j - a[i]][1];
				dp[j][1] |= dp[j - a[i]][0];
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; i ++) {
			if (dp[i][1] && !dp[i][0]) {
				++ ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
