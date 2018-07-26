#include <bits/stdc++.h>
using namespace std;
const int MAX = 20005;
const int mod = 210;
int n, v[MAX], dp[210][210][2];

#define MLE
#ifdef MLE
int dfs(int x, int k, int who)
{
	if (x == n + 1) return 0;
	if (dp[x][k][who] != -1) return dp[x][k][who];
	int oth = - (~who);
	if (who == 0) {
		if (x + k + 1 <= n + 1)
			return dp[x][k][who] = max(v[x + k - 1] - v[x - 1] + dfs(x + k, k, oth), 
									dfs(x + k + 1, k + 1, oth) + v[x + k] - v[x - 1]);
		else if (x + k <= n + 1)
			return dp[x][k][who] = v[x + k - 1] - v[x - 1] + dfs(x + k, k, oth);
	} else {
		if (x + k + 1 <= n + 1)
			return dp[x][k][who] = min(- v[x + k - 1] + v[x - 1] + dfs(x + k, k, oth), 
									dfs(x + k + 1, k + 1, oth) - v[x + k] + v[x - 1]);
		else if (x + k <= n + 1)
			return dp[x][k][who] = - v[x + k - 1] + v[x - 1] + dfs(x + k, k, oth);
	}
	return dp[x][k][who] = 0;
}
#endif

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		v[0] = 0; 
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &v[i]);
			v[i] += v[i - 1];
		}
		memset(dp, 0, sizeof dp);
		int maxk = sqrt(2 * n) + 1;
		for (int i = n; i >= 1; i --) {
			for (int j = maxk; j >= 1; j --) {
				if (i + j + 1 <= n + 1) {
					dp[i % mod][j][0] = max( + v[i + j] - v[i - 1] + dp[(i + j + 1) % mod][j + 1][1], 
									 + v[i + j - 1] - v[i - 1] + dp[(i + j) % mod][j][1]);
					dp[i % mod][j][1] = min( - v[i + j] + v[i - 1] + dp[(i + j + 1) % mod][j + 1][0],
									 - v[i + j - 1] + v[i - 1] + dp[(i + j) % mod][j][0]);
				} else if (i + j <= n + 1) {
					dp[i % mod][j][0] =  + v[i + j - 1] - v[i - 1] + dp[(i + j) % mod][j][1];
					dp[i % mod][j][1] =  - v[i + j - 1] + v[i - 1] + dp[(i + j) % mod][j][0];
				}
			}
		}
		printf("%d\n", dp[1][1][0]);
	}
}
