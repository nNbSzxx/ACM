#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
long long n, v[MAX], t[MAX], dif[MAX], ans[MAX];
long long sumt[MAX];

int main()
{
	memset(dif, 0, sizeof dif);
	memset(ans, 0, sizeof ans);
	scanf("%lld", &n);
	sumt[0] = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &v[i]);
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &t[i]);
		sumt[i] = sumt[i - 1] + t[i];
	}
	for (int i = 1; i <= n; i ++) {
		int l = 0, r = n, mid, loc = 0;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (sumt[mid] - sumt[i - 1] > v[i]) {
				r = mid - 1;
			} else {
				loc = mid;
				l = mid + 1;
			}
		}
		//printf("%d\n", loc);
		dif[i] += 1;
		dif[loc + 1] -= 1;
		ans[loc + 1] += (v[i] - sumt[loc] + sumt[i - 1]);
	}
	for (int i = 1; i <= n; i ++) {
		dif[i] += dif[i - 1];
		ans[i] += dif[i] * t[i];
	}
	for (int i = 1; i <= n; i ++) {
		printf("%lld ", ans[i]);
	}
	return 0;
}
