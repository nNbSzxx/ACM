#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10100;

int main()
{
	int dp[MAX];	
	int n,m;
	int c[5];
	while (~scanf("%d%d",&n,&m)) {
		memset(dp,0x8f,sizeof(dp));
		dp[0] = 0;
		for (int i = 1; i <= 3; i ++) {
			scanf("%d",&c[i]);
		}
		int minn = min(min(c[1],c[2]),c[3]);
		int maxx = max(max(c[1],c[2]),c[3]);
		if (minn * m > n || maxx * m < n) {
			printf("No\n");
			continue;
		}
		
		for (int i = 1; i <= m; i ++) {
			for (int k = 1; k <= 3; k ++) {
				for (int j = n; j >= c[k]; j --) {			
					dp[j] = max(dp[j], dp[j-c[k]]+c[k]);
				}		
			}
		}
//		for (int i = 1; i <= m; i ++) {
//			for (int j = 1; j <= n; j ++) {
//				printf("%d ",dp[i][j]);
//			}
//			printf("\n");
//		}
		if (dp[n] == n) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
