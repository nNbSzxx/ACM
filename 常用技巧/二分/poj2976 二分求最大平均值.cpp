#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double EPS = 1e-10;
const int MAX = 1010;
int n, k;
long long sum[MAX], score[MAX];
double srt[MAX];

bool check(double mid)
{
	for (int i = 1; i <= n; i ++) {
		srt[i] = score[i] - mid * sum[i];
	}
	sort(srt + 1, srt + 1 + n);
	double sumt = 0;
	for (int i = n; i > k; i --) {
		sumt += srt[i];
	}
	return sumt >= 0;
}

double bins()
{
	double l = 0, r = 1, ret = 0;
	while (r - l > EPS) {
		double mid = (l + r) / 2;
//		printf("%.6f %.6f %.6f\n", l, mid, r);
		if (check(mid)) {
			ret = mid;
			l = mid;
		} else {
			r = mid;
		}
	}
	return ret;
}

int main() 
{
	while (~scanf("%d%d", &n, &k), n || k) {
		for (int i = 1; i <= n; i ++) {
			scanf("%lld", &score[i]);
		}
		for (int i = 1; i <= n; i ++) {
			scanf("%lld", &sum[i]);
		}
		double ans = 100 * bins();
		printf("%.0f\n", ans);
	}
	return 0;
}
