#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000100;
const int INF = 999999;

inline Min( int a, int b)
{
	return a > b? b : a;
}


int main()
{
	int t;
	scanf("%d",&t);
	int dp[MAX];
	int w[MAX];
	int n,a;
	while (t --) {
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&a);
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&w[i]);
		}
		sort(w+1,w+n+1);
		for (int i = 1; i <= a; i ++) {
			dp[i] = INF;
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = a; j >= 0; j --) {
				dp[j] = Min(dp[j],dp[j % w[i]] + 1);
			}
		}
		if (dp[a] != INF)
			printf("%d\n",dp[a]);
		else 
			printf("-1\n");
	}
}
