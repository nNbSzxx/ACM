#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 4010;
int a[MAX], b[MAX], c[MAX], d[MAX];
int aa[MAX * MAX];
int n;

int up(int v)
{
	int l = 1, r = n * n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (aa[mid] <= v) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return l;
}

int low(int v)
{
	int l = 1, r = n * n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (aa[mid] < v) {
			l = mid + 1; 
		} else {
			r = mid - 1;
		}
	}
	return l;
}

int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				aa[(i - 1) * n + j] = a[i] + b[j];
			}
		}
		sort(aa + 1, aa + 1 + n * n);
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				int dif = -(c[i] + d[j]);
				ans += up(dif) - low(dif);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}




