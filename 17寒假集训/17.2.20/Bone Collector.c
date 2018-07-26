#include <stdio.h>

int main()
{
	int t,n,m,v;
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&n,&v);
		int i,j;
		int val[1001],cos[1001],dp[1001]={0};
		for (i=1;i<=n;i++) {
			scanf("%d",&val[i]);
		}
		for (i=1;i<=n;i++) {
			scanf("%d",&cos[i]);
		}
		for (i=1;i<=n;i++) {
			for (j=v;j>=cos[i];j--) {
				if (dp[j]<dp[j-cos[i]]+val[i]) {
					dp[j] = dp[j-cos[i]]+val[i];
				}
			}
		}
		printf("%d\n",dp[v]);
	}
	return 0;
}
