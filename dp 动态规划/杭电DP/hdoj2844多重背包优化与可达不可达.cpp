#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	int a[105], c[105];
	int item[10000];
	int dp[100005];
	while (~scanf("%d%d",&n,&m), n || m ) {
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= n; i ++)
			scanf("%d",&a[i]);
		for (int i = 1; i <= n; i ++)
			scanf("%d",&c[i]);
		int cnt = 0; 
		for (int i = 1; i <= n; i ++) {
			int j = 1;
			while (c[i] >= j) {
				item[++ cnt] = j * a[i];
				c[i] -= j;
				j <<= 1;
			}
			if (c[i]) {
				item[++ cnt] = c[i] * a[i];
			}
		}
		
		for (int i = 1; i <= cnt; i ++) {
			for (int j = m; j >= item[i]; j --) {
				dp[j] = max(dp[j], dp[j - item[i]] + item[i]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; i ++) {
			if (i == dp[i]) {
				ans ++;
			}
		}
		printf("%d\n", ans);
	}
}
