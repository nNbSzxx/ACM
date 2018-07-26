#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double x, y, l, d;
const double PI = 3.14159265358979323846;

double f(double cita)
{
	double ret;
	double t = l * cos(cita) + d * sin(cita) - x;
	ret = t * tan(cita) + d * cos(cita);
	return ret;
}

int main()
{
	while (~scanf("%lf%lf%lf%lf", &x, &y, &l, &d)) {
		double l = 0.0, r = PI / 2.0;
		double lmid, rmid, ret;
		while (r - l >= eps) {
			lmid = l + (r - l) / 3;
			rmid = r - (r - l) / 3;
			double t1 = f(lmid), t2 = f(rmid);
			if (t1 > t2) {
				r = rmid;
				ret = t2;
			} else {
				l = lmid;
				ret = t1;
			}
		}
		if (ret <= y) {
			puts("yes");
		} else {
			puts("no");
		}
	}
	return 0;
}
