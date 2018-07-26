#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int a[MAX], n, p, q, r;
long long dp[MAX][5];
const long long INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
	scanf("%d%d%d%d", &n, &p, &q, &r);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= 3; i ++) {
		dp[0][i] = -INF;
	}
	for (int i = 1; i <= n; i ++) {
		dp[i][0] = 0;
	}
	int k;
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i == 1) {
				k = p;
			} else if (i == 2) {
				k = q;
			} else if (i == 3) {
				k = r;
			}
			dp[j][i] = max(dp[j][i - 1] + 1LL * a[j] * k, dp[j - 1][i]);
		}
	}
	printf("%lld\n", dp[n][3]);
	return 0;
}
