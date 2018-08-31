#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 20;
const int INF = 0x3f3f3f3f;
int n, m, p;
vector<int> like[MAX + 3];
int dp[2][(1 << MAX) + 10];

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &p);
			like[i].clear();
			for (int j = 1; j <= p; j ++) {
				int t;
				scanf("%d", &t);
				like[i].push_back(t - 1);
			}
		}
		memset(dp, 0, sizeof dp);
		dp[0][(1 << m) - 1] = 1;
		int* last = dp[0];
		int* cur = dp[1];
//		queue<int>* curq = mask1;
//		queue<int>* ntq = mask2;
//		curq -> push_back((1 << m) - 1);
		for (int i = 1; i <= n; i ++) {
			for (int mask = (1 << m) - 1; mask > 0; -- mask) {
				if (last[mask] == 0) continue;
				for (int j = 0; j < like[i].size(); j ++) {
					if (mask & (1 << like[i][j])) {
						cur[mask ^ (1 << like[i][j])] += last[mask];
					}
				}
			}
			swap(cur, last);
		}
		int ans = 0;
		for (int mask = (1 << m) - 1; mask >= 0; -- mask) {
			if (m - __builtin_popcount(mask) == n) {
				ans += last[mask];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
