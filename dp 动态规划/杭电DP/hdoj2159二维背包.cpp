#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 105;
const int INF = 0x3f3f3f3f;
int main()
{
	int exp, r, n, m;
	int dp[MAX][MAX];
	int e[MAX], br[MAX]; 
	while (~scanf("%d%d%d%d",&exp, &r, &n, &m)) {
		for (int i = 1; i <= n; i ++)
			scanf("%d%d",&e[i], &br[i]);
		memset(dp,0,sizeof(dp));
		int ans = -1;
		
		for (int i = 1; i <= n; i ++) {
			for (int j = br[i]; j <= r; j ++) {
				for (int k = 1; k <= m; k ++) {
				
					dp[j][k] = max(dp[j][k], dp[j - br[i]][k - 1] + e[i]);
					if (dp[j][k] >= exp && r - j > ans) {
						ans = r - j;	
					}
				}
			}
		}
	
		printf("%d\n", ans);
	}
	
	return 0;
}
