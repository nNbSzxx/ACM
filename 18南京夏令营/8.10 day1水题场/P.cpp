#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 2e5 + 10;
int n, q;
long long sum[MAX];

int cal(long long k)
{
	static long long already = 0;
	already += k;
	if (already >= sum[n]) {
		already = 0;
		return n;
	}
	int id = lower_bound(sum + 1, sum + 1 + n, already) - (sum);
	if (sum[id] > already) {
		-- id;
	}
	return n - id;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++) {
		int a;
		scanf("%d", &a);
		sum[i] = sum[i - 1] + a;
	}
	long long already = 0;
	for (int i = 1; i <= q; i ++) {
		long long k;
		scanf("%lld", &k);
		int ans = cal(k);
		printf("%d\n", ans);
	}
	return 0;
}
