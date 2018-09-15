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
	for (int i = 1; i <= 9; i ++) {
		for (int j = 1; j <= 9; j ++) {
			for (int k = 1; k <= 9; k ++) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	memcpy(a, res, sizeof res);
	return ;
}

void qkp(long long r)
{
    memset(ret, 0, sizeof ret);
	for (int i = 1; i <= 9; i ++) {
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
	int t;
	scanf("%d", &t);
	while (t --) {
        scanf("%lld", &n);
        if (n == 1) {
            puts("3");
            continue;
        }
        for (int i = 1; i <= 9; i ++) {
            f[i] = 1;
        }

        memset(mat, 0, sizeof mat);
        mat[1][4] = 1; mat[1][7] = 1;
        mat[2][1] = 1; mat[2][4] = 1;
        mat[3][1] = 1; mat[3][7] = 1;
        mat[4][5] = 1; mat[4][8] = 1;
        mat[5][2] = 1; mat[5][8] = 1;
        mat[6][5] = 1; mat[6][8] = 1; mat[6][2] = 1;
        mat[7][9] = 1; mat[7][6] = 1;
        mat[8][6] = 1; mat[8][9] = 1; mat[8][3] = 1;
        mat[9][3] = 1; mat[9][6] = 1;
        qkp(n - 2);
        long long sum = 0;
        for (int i = 1; i <= 9; i ++) {
            for (int j = 1; j <= 9; j ++) {
                sum = (sum + ret[i][j]) % MOD;
            }
        }
        printf("%lld\n", sum);
	}

	return 0;
}

