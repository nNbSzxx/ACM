#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const long long mod = 1e9 + 7;
int n, c;

long long p(long long base, long long r)
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

int gcd(int a, int b)
{
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int t, tc = 1;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &c, &n);
		long long ans;
		if (n & 1) {
			ans = (1LL * p(c, (n + 1) / 2) * n % mod);
		} else {
			ans = (1LL * n / 2 * p(c, n / 2) % mod + 1LL * n / 2 * p(c, n / 2 + 1) % mod) % mod;
		}
		for (int i = 1; i <= n; i ++) {
			ans = (ans + p(c, gcd(n, i))) % mod;
		}
		ans = (ans * p(2 * n, mod - 2) % mod); 
		printf("Case #%d: %d\n", tc ++, ans);
	}
	return 0;
}
