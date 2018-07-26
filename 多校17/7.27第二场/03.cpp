#include <iostream>
#include <algorithm> 
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 250000 + 10;
const int mod = 1e9 + 7;
int b[MAX], maxa[MAX];
int n;

int main()
{
	while (~scanf("%d", &n)) {
		int u;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &maxa[i]);
			maxa[i] -= i;
		}
		for (int i = n - 1; i >= 1; i --) {
			maxa[i] = max(maxa[i], maxa[i + 1]);
		}
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &b[i]);
		}
		sort(b + 1, b + 1 + n);
		long long ans = 0;
		int maxb = -0x3f3f3f3f;
		int t;
		for (int i = 1; i <= n; i ++) {
			t = max(maxb, maxa[b[i]]);
			ans = (ans + t) % mod;
			maxb = max(maxb, t - n - i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
