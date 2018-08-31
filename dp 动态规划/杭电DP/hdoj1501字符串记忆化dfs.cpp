#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 205;
int dp[MAX][MAX];
char s1[MAX],s2[MAX],s3[2*MAX];
int len1,len2,len3,flag;

int dfs(int l1, int l2, int l3)
{
//	printf("%d %d %d\n",l1,l2,l3);
//	printf("%c %c %c\n",s1[l1],s2[l2],s3[l3]);
	if (flag) {
		return 1;
	}
	if (l3 == len3) {
		flag = 1;
		return 1;
	}
	if (dp[l1][l2] != -1) {
		return dp[l1][l2];
	}
	dp[l1][l2] = 0;
	if (l1 < len1 && s1[l1] == s3[l3]) {
		dp[l1][l2] = dfs(l1 + 1, l2, l3 + 1);
	}
	if (l2 < len2 && s2[l2] == s3[l3]) {
		dp[l1][l2] = dfs(l1, l2 + 1, l3 + 1);
	}
	if (dp[l1][l2]) {
		return 1;
	} else {
		return 0;
	}
	
}

int main()
{
	int t;
	scanf("%d",&t);
	int tc = 0;
	while (t --) {
		scanf(" %s %s %s",s1,s2,s3);
		len1 = strlen(s1);
		len2 = strlen(s2);
		len3 = strlen(s3);
		flag = 0;
		memset(dp,-1,sizeof(dp));
		printf("Data set %d: ", ++ tc);
		printf((dfs(0,0,0))?"yes\n":"no\n");
	}
	return 0;
}
