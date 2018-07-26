#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e9 + 10;
const int MAXM = 12; 
const int MAXP = 1e5 + 10;
const int mod = 9973;
int prime[MAXP], cnt, vis[MAXP], n, k, m;

struct Matrix {
	int r, c;
	int mat[MAXM][MAXM];
	Matrix () : r(m), c(m) {
		memset(mat, 0, sizeof mat);
	}
	Matrix (int i) : r(m), c(m) {
		memset(mat, 0, sizeof mat);
		for (int j = 1; j <= r; j ++) {
			mat[j][j] = i;
		}
	}
	Matrix (int rr, int cc) : r(rr), c(cc) {
		memset(mat, 0, sizeof mat);
	}
	void fill(void) {
		for (int i = 1; i <= r; i ++) {
			for (int j = 1; j <= c; j ++) {
				mat[i][j] = 1;
			}
		}
	}
	void mul(const Matrix& rhs) {
		Matrix ret;
		for (int i = 1; i <= r; i ++) {
			for (int j = 1; j <= rhs.c; j ++) {
				for (int k = 1; k <= c; k ++) {
					ret.mat[i][j] = ((ret.mat[i][j] + mat[i][k] * rhs.mat[k][j]) ) % mod;
				}
			}
		}
		memcpy(mat, ret.mat, sizeof ret.mat);
	}
	static Matrix p(Matrix base, long long r) {
		Matrix ret;
		ret.c = ret.r = m;
		for (int i = 1; i <= m; i ++) {
			ret.mat[i][i] = 1;
		}
		while (r) {
			if (r & 1) {
				ret.mul(base);
			}
			r >>= 1;
			base.mul(base);
		}
		return ret;
	}
} g;

int quickp(int base, int r)
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


void getprime()
{
	for (int i = 2; i < MAXP; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
		}
		for (int j = 0; j < cnt; j ++) {
			if (i * prime[j] >= MAXP) break;
			vis[i * prime[j]] = 0;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}

int euler(int x)
{
	int i = 0, ret = x;
	while (prime[i] * prime[i] <= x) {
		if (x % prime[i] == 0) {
			ret = ret / prime[i] * (prime[i] - 1);
			do {
				x /= prime[i];
			} while (x % prime[i] == 0);
		}
		++ i;
	}
	if (x != 1) {
		ret = ret / x * (x - 1);
	}
	return ret % mod;
}

int gettr(const Matrix& mm, long long r)
{
	int ret = 0;
	Matrix mmm = Matrix::p(mm, r);
	for (int i = 1; i <= mmm.r; i ++) {
		ret = (ret + mmm.mat[i][i]) % mod;
	}
	return ret;
}

int polya(void)
{
	int ans = 0;
	for (int i = 1; i * i <= n; i ++) {
		if (n % i == 0) {
			if (i * i != n) {
				ans = (ans + euler(n / i) * gettr(g, i)) % mod;
				ans = (ans + euler(i) * gettr(g, n / i)) % mod;
			} else {
				ans = (ans + euler(i) * gettr(g, i)) % mod;
			}
		}
	}
	ans = (ans * quickp(n % mod, mod - 2)) % mod;
	return ans;
}

int main()
{
	getprime();
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d", &n, &m, &k);
		g.c = g.r = m;
		g.fill();
		int u, v;
		for (int i = 1; i <= k; i ++) {
			scanf("%d%d", &u, &v);
			g.mat[u][v] = g.mat[v][u] = 0;
		}
		printf("%d\n", polya());
	}
}
