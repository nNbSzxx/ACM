#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int cnt, prime[MAX], vis[MAX], mu[MAX];

void init()
{
	memset(vis, 0, sizeof vis);
	mu[1] = 1;
	cnt = 0;
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
			mu[i] = -1;
		}
		for (int j = 0; j < cnt; j ++) {
			if (prime[j] * i >= MAX) break;
			vis[i * prime[j]] = 1; 
			if (i % prime[j]) mu[i * prime[j]] = - mu[i];
			else {
				mu[i * prime[j]] = 0;
				break;
			}
		}
	}
}

int main()
{
	init();
	int t, tc = 1;
	scanf("%d", &t);
	while (t --) {
		int b, d, k;
		scanf("%*d%d%*d%d%d", &b, &d, &k);
		if (k == 0) {
			printf("Case %d: %d\n", tc ++, 0);
			continue;
		}
		b /= k;
		d /= k;
		if (b < d) swap(b, d);
		long long ans = 0, t = 0;
		for (int i = 1; i <= b; i ++) {
			ans += 1LL * mu[i] * (b / i) * (d / i);
		}
		for (int i = 1; i <= d; i ++) {
			t += 1LL * mu[i] * (d / i) * (d / i);
		}
		ans -= t / 2;
		printf("Case %d: %lld\n", tc ++, ans);
	}
	return 0;
}
