#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const double EPS = 1e-8;
double x1, y1, x2, y2, x3, y3;
double w;
double a[3];
bool dun;

double dis2(double a1, double b1, double a2, double b2)
{
	return (a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2);
}

bool check(double mid)
{
	if (!dun) {
		if (a[0] >= mid) {
			double h1 = mid;
			double w1 = mid - a[0];
			
		}
	}
}

double bins(double l, double r)
{
	double mid;
	while (r - l >= EPS) {
		mid = (l + r) / 2.0;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return r;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &w);
		a[0] = dis2(x1, y1, x2, y2);
		a[1] = dis2(x1, y1, x3, y3);
		a[2] = dis2(x2, y2, x3, y3);
		sort(a, a + 3);
		if (a[0] > w) {
			puts("impossible");
			continue;
		}
		dun = false;
		if (a[0] + a[1] < a[2]) {
			dun = true;
		}
		double ans = bins(0, a[2] + 1);
	}
	return 0;
} 
