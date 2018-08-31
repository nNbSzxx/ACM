#include <bits/stdc++.h>
using namespace std;
const int MAX = 510;
int n, m, a[MAX], b[MAX];
// dp[i][j] 表示a数组前i个，b数组前j个，且b[j]在公共上升序列中的最大长度
// 压成一维，LIS和LCS的思想合起来 
int dp[MAX];

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		memset(dp, 0, sizeof dp);
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i ++) {
			scanf("%d", &b[i]);
		}
		int ans = -1;
		for (int i = 1; i <= n; i ++) {
			int maxx = 0;
			for (int j = 1; j <= m; j ++) {
				if (a[i] == b[j]) {
					dp[j] = max(dp[j], maxx + 1);
				}
				if (b[j] < a[i]) {
					maxx = max(maxx, dp[j]);
				}
				ans = max(ans, dp[j]);
			}
		}
		printf("%d\n", ans);
		if (tc != 0)
			puts(""); 
	}
	return 0;
}
