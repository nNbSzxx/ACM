#include <cstdio>
#include <algorithm>
using namespace std;

int n,p;
int c[100010],b[100010];

bool isok(double m)
{
	double charge = m * p;
	for (int i = 1; i <= n; i ++) {
		double cost = c[i] * m - b[i];
		if (cost <= 0) {
			continue;
		}
		charge -= cost;
		if (charge < 0) {
			return false;
		}
	}
	return true;
}
double bins(double l, double r)
{
	double ret = 0;
	while (r - l > 1e-8) {
		double m = (r + l) / 2;
		if (isok(m)) {
			ret = m;
			l = m;
		} else {
			r = m;
		}
	}
	return ret;
}
int main()
{
	while (~scanf("%d%d",&n,&p)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d",&c[i], &b[i]);
		}
		double ans = bins(0,double(1e10 + 5));
		if (ans >= double(1e10 + 5)) {
			puts("-1");
		} else {
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}
