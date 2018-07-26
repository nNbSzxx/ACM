#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long mat[5][5], ans[5][5], n;

void mul(long long a[][5], long long b[][5])
{
    long long ret[5][5];
    memset(ret, 0, sizeof ret);
    for (int i = 1; i <= 4; i ++) {
        for (int j = 1; j <= 4; j ++) {
            for (int k = 1; k <= 4; k ++) {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j] + mod) % mod;
            }
        }
    }
    memcpy(a, ret, sizeof mat);
}

void p (long long r)
{
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= 4; i ++) {
        ans[i][i] = 1;
    }
    while (r) {
        if (r & 1) {
            mul(ans, mat);
        }
        r >>= 1;
        mul(mat, mat);
    }
    return ;
}

int main()
{
    while (~scanf("%lld", &n)) {
        if (n == 1) {
            puts("1");
            continue;
        }
        if (n == 2) {
            puts("5");
            continue;
        }
        if (n == 3) {
            puts("11");
            continue;
        }
        memset(mat, 0, sizeof mat);
        mat[1][1] = mat[1][2] = mat[2][3] = mat[3][4] = 1;
        mat[2][1] = 5;
        mat[3][1] = 1;
        mat[4][1] = -1;
        p(n - 3);
        long long anss = (11 * ans[1][1] + 5 * ans[2][1] + ans[3][1] + ans[4][1]) % mod;
        printf("%lld\n", anss);
    }
}
