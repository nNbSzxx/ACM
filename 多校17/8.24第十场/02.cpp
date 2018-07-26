#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int table[10] = {0, 0, 31, 197, 1255, 7997};
long long n;
long long mat[5][5], ret[5][5];
void init()
{
    memset(mat, 0, sizeof mat);
    memset(ret, 0, sizeof ret);
    mat[1][1] = 4;
    mat[2][1] = 17;
    mat[3][1] = -12;
    mat[1][2] = mat[2][3]  = 1;
    ret[1][1] = ret[2][2] = ret[3][3] = 1;
}
void mul(long long a[][5], long long b[][5])
{
    long long ret[5][5] = {0};
    for (int i = 1; i <= 3; i ++) {
        for (int j = 1; j <= 3; j ++) {
            long long sum = 0;
            for (int k = 1; k <= 3; k ++) {
                sum = (sum + 1LL * a[i][k] * b[k][j] % mod + mod) % mod;
            }
            ret[i][j] = sum;
        }
    }
    memcpy(a, ret, sizeof ret);
}
void p(long long r)
{
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
        if (n <= 4) {
            printf("%d\n", table[n]);
            continue;
        }
        init();
        p(n - 4);
        long long ans = ((ret[1][1] * 1255LL) % mod +
                  (ret[2][1] * 197LL) % mod +
                  (ret[3][1] * 31LL) % mod +
                   0LL) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
