#include <algorithm> 
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n,t;
	int bit[40];
	memset(bit,0,sizeof(bit));
	scanf("%d",&n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d",&t);
		int j = 0;
		while (t) {
			if (t & 1) {
				bit[j] ++;
			}
			++ j;
			t >>= 1;
		}
	}
	long long k = 1;
	long long ans = 0;
	for (int i = 0; i < 40; i ++, k <<= 1) {
		ans += k * (bit[i] * (bit[i] - 1)) / 2 ;
	}
	printf("%lld\n",ans);
	return 0;
}
