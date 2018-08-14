#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX = 110;
long long n, m, p;
long long mat[MAX][MAX];
long long ret[MAX][MAX];

void mul(long long a[][MAX], long long b[][MAX])
{
	long long res[MAX][MAX];
	memset(res, 0, sizeof res);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			for (int k = 1; k <= n; k ++) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, res, sizeof res);
	return ;
}

void qkp(long long r)
{
	for (int i = 1; i <= n; i ++) {
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
	freopen("mpow.in", "r", stdin);
	freopen("mpow.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &p);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			scanf("%lld", &mat[i][j]);
			mat[i][j] %= p;
		}
	}
	qkp(m);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			printf("%lld ", ret[i][j]);
		}
		puts("");
	}
	return 0;
}
