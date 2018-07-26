// 一个n边形， 用c种颜色染色，旋转与翻转后的视为一种方案，求方案数 
#include <iostream>
#include <cstdio>
using namespace std;

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

long long p(long long base, long long r)
{
	long long ret = 1;
	while (r) {
		if (r & 1) {
			ret *= base;
		}
		r >>= 1;
		base *= base;
	}
	return ret;
}

int main()
{
	int c, n;
	while (scanf("%d%d", &c, &n), c && n) {
		long long ans;
		if (n & 1) {
			ans = (n * p(c, n / 2 + 1));
		} else {
			ans = (n / 2 * p(c, n / 2) + n / 2 * p(c, n / 2 + 1));
		}
		for (int i = 0; i < n; i ++) {
			ans += p(c ,gcd(n, i));
		}
		ans /= 2 * n; 
		printf("%lld\n", ans);
	}
}
