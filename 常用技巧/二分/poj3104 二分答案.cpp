#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
int a[MAX];
int n, k;

bool check(int mid)
{
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] > mid) {
			cnt += (a[i] - mid - 1) / k + 1;
			if (cnt > mid) {
				return false;
			} 
		}
	}
	return true;
}

int bins()
{
	int l = 0, r = 1e9 + 5, ret;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ret = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ret;
}

int main()
{
	while (~scanf("%d", &n)) {
		int maxx = -1;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			maxx = max(maxx, a[i]);
		}
		scanf("%d", &k);
		if (k == 1) {
			printf("%d\n", maxx);
			continue;
		}
		k -= 1;
		int ans = bins();
		printf("%d\n", ans); 
	}
	return 0;
}
