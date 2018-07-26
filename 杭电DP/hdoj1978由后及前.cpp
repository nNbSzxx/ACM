//while(true) RP++;
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 10000;
const int MAX = 105;
int main()
{
	int map[MAX][MAX], dp[MAX][MAX];
	int t;
	scanf("%d",&t);
	int n,m;
	while (t --) {
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m);
		for (int i = 1; i<= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				scanf("%d",&map[i][j]);
			}
		}
		dp[1][1] = 1;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				for (int c = 0; c <= map[i][j]; c ++) {
					for (int r = 0; r + c <= map[i][j]; r ++) {
						if ((c || r) && (i + c <= n) && (j + r <= m)) {
							dp[i + c][j + r] = (dp[i][j] + dp[i+c][j+r]) % MOD;
						}
					}
				}
			}
		}
		
		printf("%d\n",dp[n][m]);
	}
	return 0;
}

