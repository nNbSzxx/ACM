#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100010;
int main()
{
	int t,n,k;
	int c[MAX];
	bool map[MAX];
	scanf("%d",&t);
	while (t --) {
		scanf("%d",&n);
		long long pow = 1;
		int temp;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&c[i]);
		}
		
//		if (pow == 0) {
//			printf("0\n");
//			continue;
//		}
		sort(c+1,c+1+n);
		c[0] = 0;
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (pow == c[i]) {
				pow *= 2;
			} else {
				if (c[i] <= pow - 1) {
					ans = pow - 1 + c[i];
				}
			}
		}
		if (ans == 0) {
			ans = pow - 1 ;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
