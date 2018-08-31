#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 5;
const int MOD = 10007;
int mat[5][5];
int ori[5];
int n;

void mul(int a[MAX][MAX], int b[MAX][MAX])
{
	int ret[MAX][MAX];
	memset(ret, 0, sizeof ret);
	for (int i = 1; i <= 4; i ++) {
		for (int j = 1; j <= 4; j ++) {
			for (int k = 1; k <= 4; k ++) {
				ret[i][j] += a[i][k] * b[k][j] % MOD;
				ret[i][j] %= MOD;
			}
		}
	}
	memcpy(a, ret, sizeof ret);
}

void qkp(int r)
{
	int ret[MAX][MAX];
	memset(ret, 0, sizeof ret);
	for (int i = 1; i <= 4; i ++) {
		ret[i][i] = 1;
	}
	while (r) {
		if (r & 1) {
			mul(ret, mat);
		}
		mul(mat, mat);
		r >>= 1;
	}
	memcpy(mat, ret, sizeof ret);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		ori[1] = ori[2] = ori[3] = 0;
		ori[4] = 1;
		for (int i = 1; i <= 4; i ++) {
			for (int j = 1; j <= 4; j ++) {
				if (i == j) {
					mat[i][j] = 2;
				} else if (i + j == 5) {
					mat[i][j] = 0;
				} else {
					mat[i][j] = 1;
				}
			}
		}
		qkp(n);
		int ans = 0;
		for (int i = 1; i <= 4; i ++) {
			ans += mat[4][i] * ori[i] % MOD;
			ans %= MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}
