#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a,m,x,y;

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
		scanf("%d%d",&a,&m);
		int g = gcd(a,m);
		if (g != 1) {
			puts("Not Exist");
			continue;
		}
		x = x % m;
		if (x <= 0) x += m;
		printf("%d\n",x);
	}
	return 0;
}
