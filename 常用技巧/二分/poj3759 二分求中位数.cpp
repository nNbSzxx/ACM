#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
int n;
long long k;
int a[MAX];

bool check(int mid)
{
	int cnt = 0;
	for (int i = 1; i < n; i ++) {
		cnt += n - (lower_bound(a + 1, a + 1 + n, a[i] + mid) - a - 1);
	}
	if (cnt > k) {
		return true;
	} else {
		return false;
	}
}

int bins()
{
	int l = 0, r = a[n] - a[1];
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return r;
}

int main()
{
	while (~scanf("%d", &n)) {
		k = n * (n - 1) / 2;
		k = k / 2 + 1;
		-- k;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + 1 + n);
		int ans = bins();
		printf("%d\n", ans);
	}
	return 0;	
} 
