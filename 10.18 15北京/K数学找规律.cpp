#include <bits/stdc++.h>
using namespace std;
const int MAX = 65541; 
long long cnt[MAX], lcnt[MAX], tcnt[MAX];
long long n;
int k, inv;
int p(long long base, int r)
{
	long long ret = 1, mod = k;
	while (r) {
		if (r & 1) {
			ret = (ret * base) % mod;
		}
		base = (base * base) % mod;
		r >>= 1;
	}
	return ret;
}

int cal(long long x)
{
	if (x == 1) {
		return 1;
	}
	if (x & 1) {
		return (3 * cal((x - 1) / 2) + 1) % k;
	}
	return (cal(x / 2) * 3) % k;
}

void dfs(long long x)
{
	if (x == 2) {
		cnt[1] = 1;
		cnt[3] = 1;
		lcnt[3] = 1;
		return ;
	}
	if (x & 1) {
		dfs(x - 1);
		long long t = cal(x);
		lcnt[t] ++; cnt[t] ++;
	} else {
		dfs(x / 2);
		long long low = x / 2 / 2 + 1, high = x / 2;
		for (int i = 0; i < k; i ++) {
			tcnt[i] = lcnt[i * inv % k] + lcnt[(i - 1 + k) % k * inv % k];
			cnt[i] += tcnt[i];
		}
		long long left = cal(2 * high + 1);
		cnt[left] -= 1; tcnt[left] -= 1;
		if (high + 1 < low * 2) {
			left = cal(high + 1);
			cnt[left] += 1;
			tcnt[left] += 1;
		}
		memcpy(lcnt, tcnt, sizeof lcnt);
	}
	return ;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%lld%d", &n, &k);
		memset(cnt, 0, sizeof cnt);
		memset(lcnt, 0, sizeof lcnt);
		if (n == 1) {
			puts("1");
			continue;
		}
		if (k == 3) {
			if (n & 1) {
				printf("%lld\n", (n / 2) ^ (n / 2 + 1)); 
			} else {
				puts("0");
			}
			continue;
		}
		inv = p(3, k - 2);
//		printf("%d\n", inv);
		dfs(n); 
		/*
		for (int i = 1; i <= n; i ++) {
			cout << cal(i) << " ";
		}
		cout << endl;
		for (int i = 0; i < k; i ++) {
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < k; i ++) {
			cout << cnt[i] << " ";
		}
		cout << endl;
		*/
		long long ans = 0, sum = 0;
		for (int i = 0; i < k; i ++) {
			ans ^= cnt[i];
//			sum += cnt[i];
		}
//		cout << sum << endl;
		printf("%lld\n", ans);
	}
}
