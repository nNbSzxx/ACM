#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX = 15;
const long long MOD = 1e9 + 7;
long long k, n;
long long f[MAX];
long long mat[MAX][MAX];
long long ret[MAX][MAX];

void mul(long long a[][MAX], long long b[][MAX])
{
	long long res[MAX][MAX];
	memset(res, 0, sizeof res);
	for (int i = 0; i <= k; i ++) {
		for (int j = 0; j <= k; j ++) {
			for (int kk = 0; kk <= k; kk ++) {
				res[i][j] = (res[i][j] + a[i][kk] * b[kk][j]) % MOD;
			}
		}
	}
	memcpy(a, res, sizeof res);
	return ;
}

void qkp(long long r)
{
	for (int i = 0; i <= k; i ++) {
		ret[i][i] = 1;
	}
	while (r) {
		if (r & 1) {
			mul(ret, mat);
		}
		mul(mat, mat);
		r >>= 1;
	}
	return ;
}

int main()
{
	freopen("fibonacci.in", "r", stdin);
	freopen("fibonacci.out", "w", stdout);
	scanf("%lld%lld", &k, &n);
	for (int i = 0; i < k; i ++) {
		scanf("%lld", &f[i]);
		f[i] %= MOD;
		if (i != k - 1)
			f[k] = (f[k] + f[i]) % MOD;
	}
	for (int i = k - 1; i >= 0; i --) {
		scanf("%lld", &mat[k - 1][i]);
		mat[k - 1][i] %= MOD;
	}
	
	if (n < k) {
		long long sum = 0;
		for (int i = 0; i <= n; i ++) {
			sum = (sum + f[i]) % MOD;
		}
		printf("%lld %lld\n", f[n], sum);
		return 0;
	}
	for (int i = 0; i < k - 1; i ++) {
		mat[i][i + 1] = 1;
	}
	
	mat[k][k] = 1;
	mat[k][k - 1] = 1;
	/*
	for (int i = 0; i <= k; i ++) {
		for (int j = 0; j <= k; j ++) {
			printf("%lld ", mat[i][j]);
		}
		puts("");
	}
	*/
	qkp(n - k + 1);
	long long fn = 0;
	long long sum = 0;
	for (int i = 0; i <= k; i ++) {
		fn = (fn + f[i] * ret[k - 1][i]) % MOD;
		sum = (sum + f[i] * ret[k][i]) % MOD;
	}
	printf("%lld %lld\n", fn, (sum + fn) % MOD);
	return 0;
}
