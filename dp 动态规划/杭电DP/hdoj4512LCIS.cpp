#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 210;

int main()
{
	int t, n, a[MAX], b[MAX], dp[MAX][MAX];
	cin >> t;
	while (t --) {
		cin >> n;
		int ans = 1;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i ++) {
			b[i] = a[n - i + 1];
		}
		for (int i = 1; i <= n; i ++) {
			int maxl = 0;
			for (int j = 1; j <= n - i + 1; j ++) {
				dp[i][j] = dp[i - 1][j];
				if (b[j] < a[i]) {
					maxl = max(maxl, dp[i - 1][j]);
				} else if (a[i] == b[j]) {
					dp[i][j] = maxl + 1;
					if (i + j > n) {
						ans = max(ans, 2 * dp[i][j] - 1);
					} else {
						ans = max(ans, 2 * dp[i][j]);
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
