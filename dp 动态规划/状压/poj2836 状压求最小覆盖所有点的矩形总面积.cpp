#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 15;
const int INF = 0x3f3f3f3f;
int dp[(1 << MAX) + 5];
int x[MAX + 3], y[MAX + 3];
int n;

int cnt, s[MAX * MAX + 10], cover[MAX * MAX + 10];

int main()
{
	while (~scanf("%d", &n), n) {
		for (int i = 0; i < n; i ++) {
			scanf("%d%d", &x[i], &y[i]);
		}
		cnt = 0;
		memset(cover, 0, sizeof cover);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < i; j ++) {
				if (i == j) {
					continue;
				}
				s[cnt] = max(abs(x[i] - x[j]), 1) * max(abs(y[i] - y[j]), 1);
				for (int k = 0; k < n; k ++) {
					if ((x[k] - x[i]) * (x[k] - x[j]) <= 0 && 
					    (y[k] - y[i]) * (y[k] - y[j]) <= 0) {
						cover[cnt] |= (1 << k);
					}
				}
				++ cnt;
			}
		}
		memset(dp, 0x3f, sizeof dp);
		dp[(1 << n) - 1] = 0;
		for (int mask = (1 << n) - 1; mask >= 0; -- mask) {
			if (dp[mask] == INF) {
				continue;
			}
			for (int i = 0; i < cnt; i ++) {
				int newmask = mask & ~(cover[i]);
				dp[newmask] = min(dp[newmask], dp[mask] + s[i]);
			}
		}
		printf("%d\n", dp[0]);
	}
	
	return 0;
}
