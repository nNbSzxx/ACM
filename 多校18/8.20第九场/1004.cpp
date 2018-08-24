#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long gcd(long long a, long long b)
{
	long long r = 1;
	while (r) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		long long a, b, c;
		long long ra, rb, rc;
		scanf("%lld%lld%lld", &a, &b, &c);
		scanf("%lld%lld%lld", &ra, &rb, &rc);
		long long sum = a + b + c;
		long long ans = a * rb + b * rc + c * ra;
		ans -= ra * b + rb * c + rc * a;
		long long g = gcd(abs(ans), sum);
		ans /= g;
		sum /= g;
		if (sum != 1)
			printf("%lld/%lld\n", ans, sum);
		else 
			printf("%lld\n", ans);
	}
	return 0;
}
