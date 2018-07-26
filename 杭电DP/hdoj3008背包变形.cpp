#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 105;

int main() 
{
	int n, r, att;
	int c[MAX],v[MAX],dp[MAX][MAX];
	while (scanf("%d%d%d",&n,&r,&att), n || r || att)  {
		int t = 100 / att + ((100 % att)? 1 : 0);
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d",&c[i],&v[i]);
		}
		memset(dp,0,sizeof(dp));
		
		for (int i = 1; i <= t; i ++) {
			dp[i][0] = i;
		}
		c[n + 1] = 0;
		v[n + 1] = 1;
		for (int i = 0; i < r; i ++) {
			dp[1][i] = 1;
		}
		for (int i = 0; i <= 100; i ++) {
			for (int j = 1; j <= n + 1; j ++)
				if (i + r >= c[j]) 
					dp[1][i] = max(dp[1][i],v[j]);
		}
		int flag = 0, ans;
//		if (dp[0][100] >= 100) {
//			flag = 1;
//			ans = 1;
//			goto A;
//		}
		
		for (int i = 2; i <= t; i ++) {
			for (int k = 1; k <= n + 1; k ++) {
				for (int j = c[k]; j <= 100; j ++) {
					int last = j - r;
					if (last < 0) {
						dp[i][j] = i;
						continue;
					}			
//					last = j - r - c[k];
//					if (last < 0) {
//						last = 0;
//					} 
					dp[i][j - r] = max(dp[i][j - r], dp[i - 1][j - c[k]] + v[k]);
				}	
			}
//			printf("%d ",100 - (i-1)*r);
			for (int j = 100 - r + 1; j <= 100; j ++) {
				dp[i][j] = dp[i][j - 1];
//				printf("%d ",j);
			}
			if (dp[i][100] >= 100) {
				flag = 1;
				ans = i;
				goto A;
			}
			
		}
		A:
//		printf("\n");
//		for (int i = 0; i <= 5; i ++) {
//			for (int j = 0; j <= 100; j ++) {
//				printf("%d ",dp[i][j]);
//				if (!(j % 10)) {
//					printf("\n");
//				}
//			}
//			printf("\n");
//		}
//		
		if (flag) {
			printf("%d\n",ans);
		} else 
			printf("My god\n");
		
	}    
	return 0;     
}
