#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
using namespace std;

int a,b,x,y,c;
int gcd(int a, int b)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int g = gcd(b , a % b);
	int t = x;
	x = y;
	y = t - a / b * y;
	return g;
}

int main()
{
	while (~scanf("%d%d%d",&a,&b,&c),a || b || c) {
		int g = gcd(a, b);
		x *= c / g;
		y *= c / g;
		a /= g;
		b /= g;
		c /= g;
		
		x %= b;
		int yy = (c - x * a) / b;
		int minn = abs(x) + abs(yy);
		int ansx = abs(x), ansy = abs(yy), sum = abs(x) * a + abs(yy) * b;
		
		if (x < 0) {
			x += b;
		} else {
			x -= b;
		}
		yy = (c - x * a) / b;
		if (abs(x) + abs(yy) < minn) {
			minn = abs(x) + abs(yy);
			ansx = abs(x);
			ansy = abs(yy);
			sum = abs(x) * a + abs(yy) * b;
		}
		if (abs(x) + abs(yy) == minn && abs(x) * a + abs(yy) * b < sum) {
//			minn = abs(x) + abs(yy);
			ansx = abs(x); 
			ansy = abs(yy); 
			sum = abs(x) * a + abs(yy) * b;
		}
		
		y %= a;
		int xx = (c - y * b) / a;
		if (abs(xx) + abs(y) < minn) {
			minn = abs(xx) + abs(y);
			ansx = abs(xx);
			ansy = abs(y);
			sum = abs(xx) * a + abs(y) * b;
		}
		if (abs(xx) + abs(y) == minn && abs(xx) * a + abs(y) * b < sum) {
//			minn = abs(x) + abs(yy);
			ansx = abs(xx); 
			ansy = abs(y); 
			sum = abs(xx) * a + abs(y) * b;
		}
		
		if (y < 0) {
			y += a;
		} else {
			y -= a;
		}
		xx = (c - y * b) / a;
		if (abs(xx) + abs(y) < minn) {
			minn = abs(xx) + abs(y);
			ansx = abs(xx);
			ansy = abs(y);
			sum = abs(xx) * a + abs(y) * b;
		}
		if (abs(xx) + abs(y) == minn && abs(xx) * a + abs(y) * b < sum) {
//			minn = abs(x) + abs(yy);
			ansx = abs(xx); 
			ansy = abs(y); 
			sum = abs(xx) * a + abs(y) * b;
		}
		
		
		printf("%d %d\n",ansx, ansy);
	}
	return 0;
}
