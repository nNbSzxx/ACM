#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100005;
inline int Max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n;
	int dp[MAX][12];
	while (scanf("%d",&n), n) {
		memset(dp,0,sizeof(dp));
		int maxt = 0;
		for (int i = 1; i <= n; i ++) {
			int x,t;
			scanf("%d%d",&x,&t);
			dp[t][x] += 1;
			if (maxt < t)
				maxt = t;
		}
		
		for (int i = maxt - 1; i >= 0; i --) {
			for (int j = 0; j <= 10; j ++) {
				if (j >= 1 && j <= 9)
					dp[i][j] = max(max(dp[i + 1][j], dp[i + 1][j - 1]), dp[i + 1][j + 1]) + dp[i][j];
				if (j == 0)
					dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j]; 
				if (j == 10)
					dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1]) + dp[i][j];
			}
		} 
		printf("%d\n",dp[0][5]);
	}
	
}
