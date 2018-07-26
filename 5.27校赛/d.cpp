#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k, a[1010];
bool ok(int x)
{
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cnt += a[i] / x;
		if (cnt >= k)
			return true;
	}
	return false;
}
int bin(int l, int r)
{
	int mid, ans;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (mid == 0) return 0;
		if (ok(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d",&n,&k);
		for (int i = 1 ; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		printf("%d\n", bin(0, 1e8 + 1));
	}
	return 0;
}
