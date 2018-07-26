#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const long long mod = 1e9 + 7;
long long n;
long long pow2[70];
long long inv2;

long long ppow(long long base, long long r)
{
    long long ret = 1;
    while (r) {
        if (r & 1) {
            ret = (ret * base) % mod;
        }
        r >>= 1;
        base = (base * base) % mod;
    }
    return ret;
}

void init()
{
	inv2 = ppow(2, mod - 2);
	pow2[0] = 1;
	for (int i = 1; i <= 62; i ++) {
		pow2[i] = pow2[i - 1] * 2;
//		printf("%lld\n", pow2[i]);
	}
	
}

long long getZero(long long x)
{
	long long ret = 0;
	while (x) {
		ret += x;
		x >>= 1;
	}
	return ret;
}

long long bins()
{
	long long l = max(1LL, n / 2 - 1000), r = min(n, n / 2 + 1000), ret = -1;
	while (l <= r) {
		long long mid = (l + r) >> 1;
//		printf("bins: %lld %lld %lld\n", l, r, mid);
		long long zero = getZero(mid);
//		printf("zero: %lld\n", zero);
		if (zero == n) {
			return mid;
		} else if (zero > n) {
			ret = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ret; 
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%lld", &n);
		long long k = bins() - 1;
//		printf("k: %lld\n", k);
		long long ans = 1;
		long long num = k + 1;
		ans = (ans + (1 + k) % mod * (k % mod) % mod * inv2) % mod;
//		printf("ans: %lld\n", ans);
		for (int i = 2; pow2[i - 1] <= k; i ++) {
			long long fir = pow2[i - 1];
			long long step = pow2[i];
			long long ed = ((k - fir) / step * step + fir);
			long long item = ((ed - fir) / step + 1) * (i - 1);
			ans = (ans + (fir % mod + ed % mod) % mod * (item % mod) % mod * inv2 % mod) % mod;
			num += item;	
//			printf("i ans item: %lld %lld %lld\n", i, ans, item);
		}
//		if (n - num - 1 < 0) {
//			printf("!! %lld\n", n - num - 1);
//		}
		ans = (ans + (n - num) % mod * ((k + 1) % mod) % mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
