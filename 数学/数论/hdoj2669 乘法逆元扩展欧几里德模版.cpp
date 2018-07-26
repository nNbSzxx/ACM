#include <iostream>
#include <cstdio>
using namespace std;

long long a, b, x, y;
long long gcd(long long a, long long b)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long g = gcd(b, a % b);
	long long t = x;
	x = y;
	y = t - a / b * y;
	return g;
}
int main()
{
	while (~scanf("%lld%lld",&a,&b)) {
		long long g = gcd(a, b);
		if (g != 1) {
			puts("sorry");
			continue;
		}
		x %= b;
		if (x < 0) {
			x += b;
		}
		printf("%lld %lld\n",x, (1LL - a * x) / b);
	}
	return 0;
}
