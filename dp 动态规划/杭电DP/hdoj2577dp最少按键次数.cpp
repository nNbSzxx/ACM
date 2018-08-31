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
	int dp[MAX][2];
	char s[MAX];
	while (t --) {
		scanf(" %s",s);
		int len = strlen(s);
		memset(dp,0,sizeof(dp));
		dp[0][0] = 0;
		dp[0][1] = 1;
		for (int i = 1; i <= len; i ++) {
			if (s[i - 1] >= 'a' && s[i - 1] <= 'z') {
				dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
				dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
			} else {
				dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
				dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
			}
			
		} 
		printf("%d\n",min(dp[len][0], dp[len][1] + 1));
	}
	return 0;
}
