#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10005;

int main()
{
	int n, m;
	double dp[MAX];
	int w[MAX];
	double v[MAX];
	while (~scanf("%d%d",&n,&m), n || m) {
		for (int i = 1; i <= m; i ++) {
			scanf("%d%lf", &w[i], &v[i]);
			v[i] = 1 - v[i];
		}
		//memset(dp,0,sizeof(dp));
		for (int i = 0 ; i <= n; i ++)
			dp[i] = 1;
		for (int i = 1; i <= m; i ++) {
			for (int j = n; j >= w[i]; j --) {
				dp[j] = min(dp[j], dp[j - w[i]] * v[i]);
			}
		}
		printf("%.1f%%\n",(1 - dp[n]) * 100);
	} 		
	return 0;
}
