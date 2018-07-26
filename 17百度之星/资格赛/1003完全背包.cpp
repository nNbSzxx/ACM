#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e3 + 10;
const int MAXN = 1e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int n, m, a[MAXN], b[MAXN];
int kk[MAX], p[MAX];
long long dp[MAX][15], ans;

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		memset(dp, 0x3f, sizeof dp);
		for (int i = 0; i < 15; i ++) {
			dp[0][i] = 0;
		}
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d", &a[i], &b[i]);
		}
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d", &kk[i], &p[i]);
		}
		for (int i = 1; i <= m; i ++) {
			for (int j = 1; j <= 1000; j ++) {
				for (int k = 0; k < min(p[i], 11); k ++) {
					int att = p[i] - k;
					if (att <= j) {
						dp[j][k] = min(dp[j][k], dp[j - att][k] + kk[i]);
					} else {
						dp[j][k] = min(dp[j][k], dp[0][k] + kk[i]);
					}
				}
			}
		}
		for (int i = 0; i <= 10; i ++) {
			for (int j = 999; j >= 0; j --) {
				dp[j][i] = min(dp[j][i], dp[j + 1][i]);
			}
		}
		ans = 0;
		int flag = 1;
		for (int i = 1; i <= n; i ++) {
			if (dp[a[i]][b[i]] != INF) {
				ans += dp[a[i]][b[i]];
			} else {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("%lld\n", ans);
		} else {
			puts("-1");
		}
	}
	return 0;
	
}
