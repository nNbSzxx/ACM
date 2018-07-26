#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int a,b,c,x,y,A;

int gcd(int a, int b)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int g = gcd(b, a % b);
	int t = x;
	x = y;
	y = t - a / b * y;
	return g;
}

int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		b = 9973;
		scanf("%d%d",&A, &a);
		int g = gcd(a, b);
		x = x % b;
		if (x < 0) {
			x += b;
		}
		printf("%d\n", A * (x % 9973) % 9973);
	}
	return 0;
}
