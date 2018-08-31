#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
double dp[MAX];
int n, m, fly[MAX];

int main()
{
	while (~scanf("%d%d", &n, &m), n || m) {
		memset(fly, -1, sizeof fly);
		int u, v; 
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d", &u, &v);
			fly[u] = v;
		}
		dp[n] = 0;
		for (int i = n - 1; i >= 0; i --) {
			if (fly[i] != -1) {
				dp[i] = dp[fly[i]];
			} else {
				dp[i] = 0;
				for (int j = 1; j <= 6; j ++) {
					dp[i] += 1.0 / 6 * dp[(i + j > n)? n : i + j];
				}
				dp[i] += 1;
			}
		}
		printf("%.4f\n", dp[0]);
	}
}

 
