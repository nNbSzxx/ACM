#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

inline Max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n,m;
	int num[1020];
	int dp[10008];
	int val[1000],cost[1000];
	while (~scanf("%d%d",&n,&m)) {
		memset(num, 0, sizeof(num));
		memset(val, 0, sizeof(val));
		memset(cost, 0, sizeof(cost));
		memset(dp, 0, sizeof(dp));
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			int v,c;
			scanf(" %*s%d%d",&v,&c);
			num[v * 100 + c * 1] ++;
		}
		for (int i = 0; i <= 1015; i ++) {
			int v = i / 100;
			int c = i % 100;
	
			int j = 1;
			while (num[i] >= j) {
				num[i] -= j;
				val[++cnt] = j * v;
				cost[cnt] = j * c;
				j <<= 1;
			}
			if (num[i]) {
				val[++cnt] = num[i] * v;
				cost[cnt] = num[i]  * c;
			}
		}
		for (int i = 1; i <= cnt; i ++) {
			for (int j = m; j >= cost[i]; j --) {
				dp[j] = Max(dp[j], dp[j - cost[i]] + val[i]);
			}
		}
		printf("%d\n",dp[m]);
	}
	return 0;
}
