#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
long long n, dp[MAX];
int k;
struct range {
	long long l, r;
} r[MAX];
bool cmp(const range& r1, const range& r2)
{
	return r1.r < r2.r;
}

int bs(int x, long long aim)
{
	int l = 1, rr = x - 1, ret = 0;
	int mid;
	while (l <= rr) {
		mid = (l + rr) >> 1;
		if (r[mid].r < aim) {
			ret = max(ret, mid);
			l = mid + 1;
		} else {
			rr = mid - 1;
		}
	}
	return ret;
}

int main()
{
	while (~scanf("%lld%d", &n, &k)) {
		for (int i = 1; i <= k; i ++) {
			scanf("%lld%lld", &r[i].l, &r[i].r);
		}
		sort(r + 1, r + 1 + k, cmp);
		int loc;
		long long ans = 0;
		r[0].l = r[0].r = dp[0] = 0;
		for (int i = 1; i <= k; i ++) {
			dp[i] = dp[i - 1];
			loc = bs(i, r[i].l);
			dp[i] = max(dp[i], dp[loc] + r[i].r - r[i].l + 1);
		}
		printf("%lld\n", n - dp[k]);
	}
	return 0;
}
