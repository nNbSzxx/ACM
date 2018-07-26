#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long pre[255][255], pre1[255][255], dp[1010 * 250], dp1[1010 * 250];
int n, t;
int sum;

void init()
{
	// 打表，根据t打出一个长度为i的块做j个梦的情况数 
	for (int i = 0; i < 255; i ++) {
		pre[i][0] = 1;
	}
	for (int i = 1; i < 255; i ++) {
		for (int j = 1; j <= i; j ++) {
			pre[i][j] = (pre[max(i - t - 1, 0)][j - 1] + pre[i - 1][j]) % MOD; 
		}
	}
	// pre1[i][j] 长度为i的块做j个梦，且放第i个食材一定做梦
	for (int i = 1; i < 255; i ++) {
		for (int j = 1; j <= i; j ++) {
			pre1[i][j] = pre[max(i - t - 1, 0)][j - 1];
		}
	}
	// 求前缀和 
	for (int i = 1; i < 255; i ++) {
		for (int j = 1; j < 255; j ++) {
			pre[i][j] = (pre[i][j] + pre[i][j - 1]) % MOD;
			pre1[i][j] = (pre1[i][j] + pre1[i][j - 1]) % MOD;
		}
	}
	 
}

int main()
{
	freopen("kebab.in", "r", stdin);
	freopen("kebab.out", "w", stdout);
	int q, x;
	scanf("%d%d", &n, &t);
	init();
	sum = 0;
	// dp表示所有合法总数
	// dp1表示末尾食材做梦时的总数 
	dp[0] = 1;
	dp1[0] = 0;
	for (int block = 1; block <= n; ++ block) {
		scanf("%d%d", &q, &x);
		for (int i = 1; i <= q; i ++) {
			dp[sum + i] = dp[sum + i - 1];
			if (i <= t + 1) { // 末尾做梦，状态一定是从前一个块转移来的 
				for (int j = 1; j < i; j ++) {
					dp1[sum + i] = (dp1[sum + i] + pre1[j][q - x] * dp1[max(sum + i - t - j, 0)]) % MOD;
				}
				// j == i，不需要要求sum + i - t - i位必须是1 
				dp1[sum + i] = (dp1[sum + i] + pre1[i][q - x] * dp[max(sum - t, 0)]) % MOD;
			} else { // 末尾做梦的状态是从当前块转移来的，不从末尾开始，要从转移到上一个块的位置开始 
				for (int j = i - t; j < i; j ++) {
					dp1[sum + i] = (dp1[sum + i] + pre1[j][q - x] * dp1[max(sum + i - t - j, 0)]) % MOD;
				}
				dp1[sum + i] = (dp1[sum + i] + pre1[i][q - x] * dp[max(sum - t, 0)]) % MOD;
			}
			// 末尾做梦和末尾不做梦相加 
			dp[sum + i] = (dp[sum + i] + dp1[sum + i]) % MOD;
		}
		sum += q;
	}
	printf("%lld\n", dp[sum]);
	
	return 0;
}
