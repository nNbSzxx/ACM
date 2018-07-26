#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e4 + 10;
int n, m; 
int mu[MAX], fac[MAX], d[MAX], prime[MAX], cnt, vis[MAX];
void init()
{
	mu[1] = 1;
	fac[1] = 1;
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
			mu[i] = -1;
			fac[i] = 2;
			d[i] = 1;
		}
		for (int j = 0; j < cnt; j ++) {
			if (1LL * i * prime[j] >= MAX) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				fac[i * prime[j]] = fac[i] / (d[i] + 1) * (d[i] + 2);
				d[i * prime[j]] = d[i] + 1;
			} else {
				mu[i * prime[j]] = -mu[i];
				fac[i * prime[j]] = fac[i] * 2;
				d[i * prime[j]] = 1;
			}
		}
	}
	for (int i = 1; i < MAX; i ++) {
		mu[i] += mu[i - 1];
		fac[i] += fac[i - 1];
	}
	return ;
}
 
int main()
{
	init();
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &m);
		if (n < m) swap(n, m);
		int last;
		long long ans = 0;
		for (int i = 1; i <= m; i = last + 1) {
			// n / (n / i) 是满足n / i = (n / i)的i的最大值 
			last = min(n / (n / i), m / (m / i));
			ans += 1LL * (mu[last] - mu[i - 1]) * fac[n / i] * fac[m / i];
		}
		printf("%lld\n", ans);
	}
}
