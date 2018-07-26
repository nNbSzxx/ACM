#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
const long long mod = 1e9 + 7;
long long n, k;
long long f[4], mat[5][5], t[5][5];
int prime[MAX], cnt, vis[MAX];

void init()
{
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
		}
		for (int j = 0; j < cnt; j ++) {
			if (1LL * prime[j] * i >= MAX) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	return ;
}

long long phi(long long x)
{
	if (x == 1) return 1;
	int i = 0;
	long long ret = x;
	while (i < cnt && 1LL * prime[i] * prime[i] <= x) {
		if (x % prime[i] == 0) {
//			cout << prime[i] << " " << x << " " << ret << endl;
			ret = ret / prime[i] * (prime[i] - 1);
			do {
				x /= prime[i];
			} while (x % prime[i] == 0);
		}
		++ i;
	}
	if (x > 1) ret = ret / x * (x - 1);
//	cout << ret << endl;
	return ret;
}

void mul(long long m1[5][5], long long m2[5][5])
{
	long long m3[5][5];
	memset(m3, 0, sizeof m3);
	/*
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) {
			cout << m1[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) {
			cout << m2[i][j] << " ";
		}
		cout << endl;
	}
	*/
	for (int i = 1; i <= 2; i ++) {
		for (int j = 1; j <= 2; j ++) {
			for (int k = 1; k <= 2; k ++) {
				m3[i][j] = (m3[i][j] + m1[i][k] * m2[k][j] % mod) % mod;
			}
		}
	}
	/*
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) {
			cout << m3[i][j] << " ";
		}
		cout << endl;
	}
	*/
	memcpy(m1, m3, sizeof m3);
}

void p(long long m[5][5], long long r)
{
	long long ret[5][5];
	memset(ret, 0, sizeof ret);
	for (int i = 1; i <= 2; i ++) {
		ret[i][i] = 1;
	}
	while (r) {
		/*
		cout << "r: " << r << endl;
		for (int i = 1; i <= 3; i ++) {
			for (int j = 1; j <= 3; j ++) {
				cout << m[i][j] << " "; 
			} 
			cout << endl;
		}
		*/
		if (r & 1) {
			mul(ret, m);
		}
		r >>= 1;
		mul(m, m);
	}
	memcpy(m, ret, sizeof ret);
}

long long get(long long x)
{
	if (x == 1) return 0;
	if (x < 4) return f[x];
	memcpy(t, mat, sizeof t);
	p(t, x - 3);
	/*
	cout << "x: " << x << endl; 
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	*/
	long long ret = 
	( f[2] * t[1][2] % mod
	+ f[3] * t[2][2] % mod)
	% mod;
	return ret;
}

long long inv(long long x)
{
	long long r = mod - 2;
	long long ret = 1;
	while (r) {
		if (r & 1) {
			ret = ret * x % mod;
		}
		r >>= 1;
		x = x * x % mod;
	}
	return ret;
}

void polya()
{
	long long ans = 0;
	for (int l = 1; l * l <= n; l ++) {
		if (n % l == 0) {
			if (l * l == n) {
				ans = (ans + 1LL * phi(l) * get(l) % mod) % mod;
			} else {
				ans = (ans + 1LL * phi(l) * get(n / l) % mod) % mod;
				ans = (ans + 1LL * phi(n / l) * get(l) % mod) % mod;
			}
//			cout << l << " " << ans << endl;
		}
	}
	ans = (ans * inv(n) % mod * k) % mod;
	printf("%lld\n", ans); 
	return ;
}

int main()
{
	init();
	/*
	for (int i = 1; i <= 101; i ++) {
		cout << phi(i) << " "; 
	}
	cout << endl;
	*/
	while (~scanf("%lld%lld", &n, &k)) {
		f[1] = 0;
		f[2] = (k - 1) * (k - 2) % mod;
		f[3] = ((k - 1) * (k - 2) % mod * (k - 3) % mod);
//		memset(mat, 0, sizeof mat);
//		mat[1][1] = 0;
//		mat[1][1] = 1;
		mat[1][2] = k - 2;
		mat[2][1] = 1;
		mat[2][2] = k - 3;
//		cout << phi(6) << endl;
//		cout << get(n) << endl;
		polya();
	}
	return 0;
}
