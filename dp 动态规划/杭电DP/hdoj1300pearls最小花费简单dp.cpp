#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 105;
int main()
{
	int t;
	scanf("%d",&t);
	int dp[MAX];
	int num[1005];
	int cost[1005];
	int count[1005];

	while (t --) {
		int n;

		scanf("%d",&n);
		num[0] = 0;
		for (int i = 1 ;i <= n; i ++) {
			scanf("%d%d",&count[i],&cost[i]);
			num[i] = num[i - 1] + count[i];
		}
		dp[0] = 0;
		dp[1] = (count[1] + 10) * cost[1];
		for (int i = 2; i <= n; i ++) {
			dp[i] = 0x3f3f3f3f;
			for (int j = 1; j <= i; j ++) {
				if (dp[j - 1] + cost[i] * (num[i] - num[j - 1] + 10) < dp[i]) {
					dp[i] = dp[j - 1] + cost[i] * (num[i] - num[j - 1] + 10);
				}
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
