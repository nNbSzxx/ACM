#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 12;
const int MOD = 1e8;
int n, m;
int dp[2][(1 << MAX) + 5];
int can[MAX + 5][MAX + 5];

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				scanf("%d", &can[i][j]);
			}
		}
		memset(dp, 0, sizeof dp);
		int *cur = dp[1];
		int *last = dp[0];
		dp[0][0] = 1;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				for (int mask = (1 << m) - 1; mask >= 0; -- mask) {
					cur[mask] = 0;
				} 
				for (int mask = (1 << m) - 1; mask >= 0; -- mask) {
					if (!can[i][j]) {
						cur[mask & ~ (1 << j)] += last[mask];
						cur[mask & ~ (1 << j)] %= MOD;
					} else {
						if ((mask & (1 << j)) == 0 && 
						    (j == 0 || (mask & (1 << (j - 1))) == 0)) {
							cur[mask | (1 << j)] += last[mask];
							cur[mask | (1 << j)] %= MOD;    	
						}
						cur[mask & ~ (1 << j)] += last[mask];
						cur[mask & ~ (1 << j)] %= MOD;
					}
				}
				swap(cur, last);
			}
		}
		int ans = 0;
		for (int mask = (1 << m) - 1; mask >= 0; -- mask) {
			ans = (ans + last[mask]) % MOD;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
