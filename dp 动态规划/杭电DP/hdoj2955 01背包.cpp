#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 10010;

int main()
{
	int t;
	scanf("%d",&t);
	double pp;
	double dp[MAX];
	double p[110];
	int m[110];
	while (t --) {
		memset(dp, 0, sizeof(dp));
		int n;
		scanf("%lf",&pp);
		pp = 1 - pp;
		scanf("%d",&n);
		int sum = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d%lf", &m[i], &p[i]);
			sum += m[i];
			p[i] = 1 - p[i];
		}
		dp[0] = 1;
		for (int i = 1; i <= n; i ++) {
			for (int j = sum; j >= m[i]; j --) {
				if (dp[j] < dp[j - m[i]] * p[i]) {
					dp[j] = dp[j - m[i]] * p[i];
				}
			}
		}
		int ans;
		for (int i = sum; i >= 0; i --) {
			if (dp[i] >= pp) {
				ans = i;
				break;
			}
		}
		printf("%d\n",ans);
	}	
	return 0;
}  
