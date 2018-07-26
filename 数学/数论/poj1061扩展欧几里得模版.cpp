#include <iostream>
#include <cstdio>
using namespace std;

long long c,a,b,x,y,l,m,n,g;

long long gcd (long long a, long long b)
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
	while (~scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)) {
		a = n - m;
		b = l;
		c = x - y;
		g = gcd(a,b);
		if (c % g) {
			puts("Impossible");
			continue;
		}
		x *= (c / g);
		y *= (c / g);
		long long k = x * g / b;
		long long ans = x - b / g * k;
		if (ans < 0) {
			ans += b / g;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
