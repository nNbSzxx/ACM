#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1010;
int dp[MAX][MAX];
int main()
{
	int t;
	scanf("%d",&t);
	
	int l[MAX], r[MAX];
	while (t --) {
		int n, m;
		char c;
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n , &m);
		for (int i = 1; i<= n; i++) {
			for (int j = 1; j <= m ; j++) {
				scanf(" %c",&c);
				if (c == 'F') {
					dp[i][j] = dp[i - 1][j] + 1;
				} 
			}
		}
		int max = 0;
		
		for (int i = 1; i <= n; i ++) {
			l[1] = 1;
			r[m] = m;
			for (int j = 2; j <= m; j ++) {
				int k = j ;
				while (k > 1 && dp[i][j] <= dp[i][k - 1]) 
					k = l[k - 1];
				l[j] = k;
			}
			for (int j = m - 1; j >= 1; j --) {
				int k = j;
				while (k < m && dp[i][j] <= dp[i][k + 1])
					k = r[k + 1];
				r[j] = k;
			}
			
			for (int j = 2; j <= n; j ++) {
				if (max < (r[j] - l[j] + 1) * dp[i][j]) {
					max = (r[j] - l[j] + 1) * dp[i][j];
				}
			}
		}
		printf("%d\n", max * 3); 
	}
	return 0;
}
