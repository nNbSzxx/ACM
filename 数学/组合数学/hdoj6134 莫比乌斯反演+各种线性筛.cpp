#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const int mod = 1e9 + 7;
int vis[MAX], mu[MAX], fac[MAX], prime[MAX], phi[MAX], d[MAX], cnt, ans[MAX];

void init()
{
	mu[1] = 1;
	phi[1] = 1;
	fac[1] = 1; 
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
			phi[i] = i - 1;
			mu[i] = -1;
			fac[i] = 2;
			d[i] = 1;
		}
		for (int j = 0; j < cnt; j ++) {
			if (1LL * i * prime[j] >= MAX) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				mu[i * prime[j]] = 0;
				fac[i * prime[j]] = fac[i] / (d[i] + 1) * (d[i] + 2);
				d[i * prime[j]] = d[i] + 1;
				break;
			} else {
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
				mu[i * prime[j]] = -mu[i];
				fac[i * prime[j]] = fac[i] * 2;
				d[i * prime[j]] = 1;
			}
		}
	}
}
void table()
{
	for (int i = 1; i < MAX; i ++) {
		fac[i] = (fac[i - 1] + fac[i]) % mod;
	}
	for (int i = 1; i < MAX; i ++) {
		for (int j = i; j < MAX; j += i) {
			if (mu[j / i] == -1) {
				ans[j] = ((ans[j] - fac[i]) % mod + mod) % mod;
			} else if (mu[j / i] == 1) {
				ans[j] = (ans[j] + fac[i]) % mod;
			}
		}
	}
	for (int i = 1; i < MAX; i ++) {
		ans[i] = (ans[i] - 1 + phi[i]) % mod;
		ans[i] = (ans[i] + ans[i - 1]) % mod;
	}
}
int main()
{
	init();
	table();
	int n;
	while (~scanf("%d", &n)) {
		printf("%d\n", ans[n]);
	}
	return 0;
}
