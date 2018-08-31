// dp[i][j] = max(dp[i][j - 1], dp[i - 1][1 .. j - 1])
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const int INF = 0x7fffffff;
int m, n, s[MAX], sum[MAX];
int dp[MAX], premax[MAX];

int main()
{
	//printf("%d\n", -INF);
	while (~scanf("%d%d", &m, &n)) {
		memset(dp, 0, sizeof dp);
		memset(premax, 0, sizeof premax);
		sum[0] = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &s[i]);
			sum[i] = sum[i - 1] + s[i];
		}
		for (int i = 1; i <= m; i ++) {
			premax[i - 1] = sum[i - 1];
			for (int j = i; j <= n; j ++) {
				premax[j] = max(premax[j - 1], dp[j]);
			}
			dp[i] = sum[i];
			for (int j = i + 1; j <= n; j ++) {
				dp[j] = max(dp[j - 1] + s[j], premax[j - 1] + s[j]);
			}
		}
		int ans = -INF;
		for (int j = m; j <= n; j ++) {
			ans = max(ans, dp[j]);
		}
		if (n == 0) puts("0");
		else printf("%d\n", ans);
	}
	return 0;
}
