#include <bits/stdc++.h>
using namespace std;
int ax, ay, bx, by, p, q, r, cx, cy, dx, dy;
double ab, cd;
const double eps = 1e-8;

inline double dis(double x1, double y1, double x2, double y2)
{
	return sqrt(1.0 * (x2 - x1) * (x2 - x1) + 1.0 * (y2 - y1) * (y2 - y1));
}

double ts2(double x, double y)
{
	double xl = cx, yl = cy, xr = dx, yr = dy;
	double lmidx, rmidx, lmidy, rmidy, t1, t2;
	double ret = dis(xl, yl, x, y) / r + dis(xl, yl, dx, dy) / q;
	while (dis(xl, yl, xr, yr) >= eps) {
		lmidx = xl + (xr - xl) / 3.0;
		lmidy = yl + (yr - yl) / 3.0;
		rmidx = xr - (xr - xl) / 3.0;
		rmidy = yr - (yr - yl) / 3.0;
		t1 = dis(x, y, lmidx, lmidy) / r + dis(dx, dy, lmidx, lmidy) / q;
		t2 = dis(x, y, rmidx, rmidy) / r + dis(dx, dy, rmidx, rmidy) / q;
		if (t1 < t2) {
			ret = t1;
			xr = rmidx;
			yr = rmidy;
		} else {
			ret = t2;
			xl = lmidx;
			yl = lmidy;
		}
	}
	return ret;
}

double ts1()
{
	double xl = ax, yl = ay, xr = bx, yr = by;
	double ret = ts2(xl, yl), lmidx, lmidy, rmidx, rmidy, t1, t2;
	while (dis(xl, yl, xr, yr) >= eps) {
		lmidx = xl + (xr - xl) / 3.0;
		lmidy = yl + (yr - yl) / 3.0;
		rmidx = xr - (xr - xl) / 3.0;
		rmidy = yr - (yr - yl) / 3.0;
		t1 = ts2(lmidx, lmidy) + dis(ax, ay, lmidx, lmidy) / p;
		t2 = ts2(rmidx, rmidy) + dis(ax, ay, rmidx, rmidy) / p;
		if (t1 < t2) {
			ret = t1;
			xr = rmidx;
			yr = rmidy;
		} else {
			ret = t2;
			xl = lmidx;
			yl = lmidy;
		}
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d%d", &ax, &ay, &bx, &by);
		scanf("%d%d%d%d%d%d%d", &cx, &cy, &dx, &dy, &p, &q, &r);
		double ans = ts1();
		printf("%.2f\n", ans);
	}
	return 0;
}
