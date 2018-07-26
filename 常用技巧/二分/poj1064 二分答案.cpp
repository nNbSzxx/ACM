#include <cstdio>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 10;
const double EPS = 1e-10;
int n, k;
double len[10010];

bool judge(double x)
{
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cnt += (int)(len[i] / x);
	}
	return (cnt >= k);
}

double bins()
{
	double ret = 0.00;
	double l = 0, r = MAX;
	while (r - l > EPS) {
		double mid = (l + r) / 2;
		if (judge(mid)) {
			ret = mid;
			l = mid;
		} else {
			r = mid;
		}
	}
	return r;
}

int main()
{
	while (~scanf("%d%d", &n, &k)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%lf", &len[i]);
		}
		double ans = bins();
		printf("%.2f\n", 1.0 * floor(ans * 100) / 100);
	}
	return 0;
}
