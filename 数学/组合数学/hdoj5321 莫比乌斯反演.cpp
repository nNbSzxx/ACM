#include <bits\stdc++.h>
using namespace std;
const long long mod = 258280327LL;
const int MAX = 1e5 + 10;
int n, maxx, vis[MAX], mu[MAX], prime[MAX], pcnt;
long long f[2][MAX], fac[MAX], inv[MAX], cnt[MAX];

long long p(long long base, long long r)
{
	long long ret = 1;
	while (r) {
		if (r & 1) {
			ret = (ret * base) % mod;
		}
		base = (base * base) % mod;
		r >>= 1;
	}
	return ret;
}

void init()
{
	fac[0] = fac[1] = 1;
	inv[0] = inv[1] = 1;
	for (int i = 2; i < MAX; i ++) {
		fac[i] = (1LL * fac[i - 1] * i) % mod;
		inv[i] = p(fac[i], mod - 2);
	}
	mu[1] = 1;
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[pcnt ++] = i;
			mu[i] = -1;
		}
		for (int j = 0; j < pcnt; j ++) {
			if (1LL * prime[j] * i >= MAX) {
				break;
			}
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				break;
			} else {
				mu[i * prime[j]] = - mu[i];
			}
		}
	}
}
inline long long A(int n, int m)
{
	return (fac[n] * inv[n - m]) % mod;
}
void solve()
{
	memset(f, 0, sizeof f);
	for (int i = 1; i <= maxx; i ++) {
		if (cnt[i]) {
			for (int j = 1; j <= cnt[i]; j ++) {
				f[0][i] = (f[0][i] + A(cnt[i], j) * fac[n - j + 1]) % mod;
			}
			f[1][i] = (f[1][i] + cnt[i] * p(2, cnt[i] - 1)) % mod;
		}
	}
}
int main()
{
	init();
	while (~scanf("%d", &n)) {
		memset(cnt, 0, sizeof cnt); 
		maxx = -1;
		int t;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &t);
			maxx = max(t, maxx);
			++ cnt[t];
		}
		for (int i = 1; i <= maxx; i ++) {
			for (int j = 2 * i; j <= maxx; j += i) {
				cnt[i] = (cnt[i] + cnt[j]) % mod;
			}
		}
		solve();
		long long ans0 = 0, ans1 = 0;
		for (int i = 1; i <= maxx; i ++) {
			long long t0 = 0, t1 = 0;
			for (int j = i; j <= maxx; j += i) {
				t0 = (t0 + mu[j / i] * f[0][j]) % mod;
				t1 = (t1 + mu[j / i] * f[1][j]) % mod;
			}
			ans0 = (ans0 + 1LL * t0 * i) % mod;
			ans1 = (ans1 + 1LL * t1 * i) % mod;
		}
		if (ans0 > ans1) {
			printf("Mr. Zstu %lld\n", ans0);
		} else if (ans0 < ans1) {
			printf("Mr. Hdu %lld\n", ans1);
		} else {
			printf("Equal %lld\n", ans0);
		}
	}
}
