#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 85;

long long mod;
int n, m;
long long dp[MAX * MAX][MAX][MAX];

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%lld", &n, &m, &mod);
		dp[1][1][1] = n * m % mod;
		for (int cur = 2; cur <= n * m; cur ++) {
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= m; j ++) {
					dp[cur][i][j] = 0;
					dp[cur][i][j] += dp[cur - 1][i - 1][j] * (n - (i - 1)) * (j);
					dp[cur][i][j] += dp[cur - 1][i][j - 1] * (i) * (m - (j - 1));
					dp[cur][i][j] += dp[cur - 1][i][j] * (i * j - cur + 1);
					if (dp[cur][i][j] > mod) dp[cur][i][j] %= mod;
				}
			}
		}
		printf("%lld\n", dp[n * m][n][m]);
	}
	return 0;
}




