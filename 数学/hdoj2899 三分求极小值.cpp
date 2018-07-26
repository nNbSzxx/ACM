#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double y;
// F(x) = 6 * x^7+8*x^6+7*x^3+5*x^2-y*x (0 <= x <=100)

inline double f(double x)
{
	return 6.0 * pow(x, 7) + 8.0 * pow(x, 6) + 7.0 * x * x * x + 5.0 * x * x - y * x;
}

double ts(double l, double r)
{
	int tc = 1;
	double lmid, rmid, ret = f(l), t1, t2;
	while (r - l >= eps) {
		lmid = l + (r - l) / 3.0;
		rmid = r - (r - l) / 3.0;
		t1 = f(lmid); t2 = f(rmid);
		if (t1 < t2) {
			ret = t1;
			r = rmid;
		} else {
			ret = t2;
			l = lmid;
		}
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%lf", &y);
		double ans = ts(0.0, 100.0);
		printf("%.4f\n", ans);
	}
	
	return 0;
}
