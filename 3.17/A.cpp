#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>
using namespace std;

int main()
{
	int t;
	long long n;
	scanf("%d",&t);
	int tc = 0;
	while (t --) {
		scanf("%lld",&n);
		bitset<100010> bi(0);
		int bound = sqrt(n);
		long long temp;
		long long ans = n;
		long long loc;
		printf("%d\n",bound);
		for (int i = 1; i <= bound; i ++) {
			if (!bi[i]) {	
				temp = i * i;
				loc = i;
				while (temp <= n) {
//					printf("%d ",temp);
					temp <<= 1;
					loc <<= 1;
					if (loc <= bound)
						bi[loc] = 1;
					ans --;			
				}
			}
		}
//		printf("\n");
		printf("Case %d: %lld\n",++tc,ans);
	}
}
