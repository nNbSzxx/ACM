#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
const int UPPER = 1e6 + 1;
const double EPS = 1e-8;
int n, k;
int v[MAX], w[MAX], ans[MAX];
struct item {
	int id;
	double val;
} m[MAX];

bool cmp(const item& m1, const item& m2)
{
	return m1.val > m2.val;
}

bool check(double mid)
{
	for (int i = 1; i <= n; i ++) {
		m[i].id = i;
		m[i].val = v[i] - w[i] * mid;
	}
	sort(m + 1, m + 1 + n, cmp);
	double sum = 0;
	for (int i = 1; i <= k; i ++) {
		sum += m[i].val;
	}
	if (sum >= 0) {
		for (int i = 1; i <= k; i ++) {
			ans[i] = m[i].id;
		}
		return true;
	} else {
		return false;
	}
}

void bins()
{
	double l = 0, r = UPPER;
	while (r - l > EPS) {
		double mid = (l + r) / 2.0;
		if(check(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
}

int main()
{
	while (~scanf("%d%d", &n, &k)) {
		for (int i = 1; i <= k; i ++) {
			ans[i] = i;
		} 
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d", &v[i], &w[i]);
		}
		bins();
		printf("%d", ans[1]);
		for (int i = 2; i <= k; i ++) {
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}
