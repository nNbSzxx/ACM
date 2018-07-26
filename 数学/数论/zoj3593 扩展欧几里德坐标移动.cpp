#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long s,e,c,a,b,x,y;

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
	int t;
	scanf("%d",&t);
	while (t --) {
		scanf("%lld%lld%lld%lld",&s,&e,&a,&b);
		c = s - e;
		if (c < 0) {
			c = -c;
		}
		if (c == 0) {
			puts("0");
			continue;
		}
		long long g = gcd(a, b);
		if (c % g != 0) {
			puts("-1");
			continue;
		}
		x *= c / g;
		y *= c / g;
		
		long long ans = 0x3f3f3f3f3f3f3f3f;
		long long mid = (y - x) / (a / g + b / g), f;
		for (long long i = mid - 1; i <= mid + 1; i ++) {  
	        if(abs(x + b / g * i) + abs (y - a / g * i) == abs(x + b / g * i + y - a / g * i))  
	            f = max(abs(x + b / g * i), abs(y - a / g * i));  
	        else  
	            f = abs(x - y + (a / g + b / g) * i);
	        ans = min( ans, f);  
	    }  
		printf("%lld\n", ans);
	}
	
	return 0;
}
