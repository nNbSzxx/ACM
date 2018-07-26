#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 10;
int n, mod, vis[MAX], prime[MAX], cnt, euler[MAX];

void init()
{
	euler[1] = 1;
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
			euler[i] = i - 1;
		}
		for (int j = 0; j < cnt; j ++) {
			if (1LL * i * prime[j] >= MAX) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				euler[i * prime[j]] = euler[i] * prime[j];
				break;
			} else {
				euler[i * prime[j]] = euler[i] * (prime[j] - 1);
			}
		}
		//cout << euler[i] << " " ;
	}
}

int p(int base, int r)
{
	int ret = 1;
	while (r) {
		if (r & 1) {
			ret = (ret * base) % mod;
		}
		r >>= 1;
		base = (base * base) % mod;
	}
	return ret;
}

int getEuler(int x)
{
	if (x < MAX) return euler[x];
	int ret = x;
	for (int i = 0; i < cnt; i ++) {
		if (prime[i] * prime[i] > x) break;
		if (x % prime[i] == 0) {
			ret = ret / prime[i] * (prime[i] - 1);
			x /= prime[i];
			while (x % prime[i] == 0) {
				x /= prime[i];
			} 
		}
	}
	if (x != 1) {
		ret = ret / x * (x - 1);
	}
	return ret;
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &mod);
		int ans = 0;
		//cout << n << endl;
		for (int l = 1; l * l <= n; l ++) {
			if (n % l == 0) {
				if (l * l < n) {
					ans = (ans + getEuler(l) % mod * p(n % mod, (n / l - 1) )) % mod;
					ans = (ans + getEuler(n / l) % mod * p(n % mod, (l - 1) )) % mod;
				} else {
					ans = (ans + getEuler(l) % mod * p(n % mod, (l - 1) )) % mod;
				}
				//cout << l << " " << ans << endl;
			}
		}
		printf("%d\n", ans);
	}
}
