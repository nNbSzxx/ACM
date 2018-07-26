//while(true) RP++;
#include <cstdio>
#include <cstring> 
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 2050;
int main() {
	int n,k;
	int dp[MAX][MAX/2];
	int num[MAX];
	while (~scanf("%d%d",&n,&k)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&num[i]);
		}
		sort(num+1, num+1+n);
		memset(dp,0x3f,sizeof(dp));
		for (int i = 0; i <= n; i ++) {
			dp[i][0]  = 0;
		}
		for (int i = 2; i <= n; i ++) {
			for (int j = 1; j <= i/2 && j <= k; j ++) {
				if (j == i * 2)
					dp[i][j] = dp[i - 2][j - 1] + (num[i] - num[i - 1]) * (num[i] - num[i - 1]);
				else 
					dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (num[i] - num[i - 1]) * (num[i] - num[i - 1]));
				
			}
		}
		printf("%d\n",dp[n][k]);
	}
	
	return 0;
}

