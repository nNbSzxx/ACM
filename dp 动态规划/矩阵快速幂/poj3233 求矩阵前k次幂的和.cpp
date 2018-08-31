#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 30 * 2 + 3;
int n, k, mod;
int mat[MAX][MAX];
int ori[MAX][MAX];

void mul(int a[MAX][MAX], int b[MAX][MAX])
{
	int ret[MAX][MAX];
	memset(ret, 0, sizeof ret);
	for (int i = 1; i <= 2 * n; i ++) {
		for (int j = 1; j <= 2 * n; j ++) {
			for (int k = 1; k <= 2 * n; k ++) {
				ret[i][j] += a[i][k] * b[k][j] % mod;
				ret[i][j] %= mod;
			}
		}
	}
	memcpy(a, ret, sizeof ret);
}

void qkp(int r)
{
	int ret[MAX][MAX];
	memset(ret, 0, sizeof ret);
	for (int i = 1; i <= 2 * n; i ++) {
		ret[i][i] = 1;
	}
	while (r) {
		if (r & 1) {
			mul(ret, mat);
		}
		r >>= 1;
		mul(mat, mat);
	}
	memcpy(mat, ret, sizeof ret);
}

int main()
{
	scanf("%d%d%d", &n, &k, &mod);
	memset(mat, 0, sizeof mat);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			scanf("%d", &mat[i][j]);
			mat[i][j] %= mod;
			ori[i][j] = mat[i][j];
		}
	}
	for (int i = n + 1; i <= 2 * n; i ++) {
		mat[i][i - n] = 1 % mod;
		mat[i][i] = 1 % mod;
	}
	qkp(k);
	int ans[MAX][MAX];
	memset(ans, 0, sizeof ans);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			for (int k = 1; k <= n; k ++) {
				ans[i][j] += mat[i + n][k] * ori[k][j];
				ans[i][j] %= mod;
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			printf(j == n ? "%d\n" : "%d ", ans[i][j]);
		}
	}
	return 0;
}





