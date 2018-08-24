#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const long long MOD = 998244353;

long long qkp(long long base, long long r)
{
	long long ret = 1;
	while (r) {
		if (r & 1) {
			ret = (ret * base) % MOD;
		}
		r >>= 1;
		base = (base * base) % MOD;
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		long long a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		long long ans = 0;
		long long p2a = qkp(2, a) % MOD;
		long long p2b = (b == 0) ? 0 : (qkp(2, b) - 1 + MOD) % MOD;
		long long p2c = (c == 0) ? 0 : (qkp(2, c) - 1 + MOD) % MOD;
		ans = (ans + p2a) % MOD;
		ans = (ans + p2a * p2b) % MOD;
		ans = (ans + p2a * p2c) % MOD;
//		ans = (ans - p2a + MOD) % MOD;
		if (d > 0) {
			ans = (ans + p2a * d) % MOD; 
		}
		if (b > 0 && c > 0) {
			ans = (ans + p2a * p2c % MOD * b) % MOD;
		}
		if (c > 0 && d > 0) {
			ans = (ans + p2a * p2c % MOD * d) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;	
} 
