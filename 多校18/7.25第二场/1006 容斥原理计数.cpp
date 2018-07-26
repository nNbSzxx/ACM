#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int mod = 998244353;
const int MAX = 3e3 + 7;
int n, m, a, b;
int pow2[MAX * MAX];
/*
int fac[MAX], invfac[MAX];
int inv[MAX * MAX];
int prepair[MAX][MAX], reprepair[MAX][MAX];
*/
//int prepairij[MAX][MAX];
int c[MAX][MAX];
int ct[MAX][MAX];
/*
int qkp(int base, int r)
{
    int ret = 1;
    while (r) {
        if (r & 1) {
            ret = (1LL* ret * base) % mod;
        }
        base = (1LL* base * base) % mod;
        r >>= 1;
    }
    return ret;
}
*/

void init()
{
    /*
    inv[1] = 1;
    for (int i = 2; i < MAX * MAX; i++)
        inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;

    fac[0] = invfac[0] = 1;
    for (int i = 1; i < MAX; i ++) {
        fac[i] = (long long)fac[i - 1] * i % mod;
        invfac[i] = qkp(fac[i], mod - 2);
    }
    */
    pow2[0] = 1;
    for (int i = 1; i <= 3000 * 3000; i ++) {
        pow2[i] = (pow2[i - 1] << 1);
        if (pow2[i] >= mod)
            pow2[i] -= mod;
    }
    /*
    for (int i = 0; i < MAX; i ++) {
        for (int j = 0; j <= i; j ++) {
            prepair[i][j] = (long long)invfac[i] * invfac[j] % mod;
            prepair[j][i] = prepair[i][j];
        }
    }
    for (int i = 0; i < MAX; i ++)
        for (int j = 0; j < MAX; j ++)
            reprepair[i][j] = prepair[i][MAX - j - 1];
    /*
    for (int i = 0; i < MAX; i ++) {
        for (int j = 0; j <= i; j ++) {
            prepairij[i][j] = 1LL * prepair[i][j] * inv[i * j] % mod;
        }
    }
    */
    c[0][0] = 1;
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i < MAX; i ++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j ++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    for (int i = 0; i < MAX; i ++) {
        for (int j = 0; j <= i; j ++) {
            ct[j][i] = c[i][j];
        }
    }
}



int main()
{
    init();
    while (~scanf("%d%d%d%d", &n, &m, &a, &b)) {
        int ans = 0;
        //int mm = MAX - m - 1, ia, ni;
        for (int i = a; i <= n; i ++) {
            /*
            ia = i - a;
            ni = n - i;
            for (int j = b; j <= m; j ++) {
                int v = (long long)prepair[ia][j - b] * reprepair[ni][mm + j] % mod *
                        pow2[ni * (m - j)] % mod * inv[i * j] % mod;
                if ((ia + j - b) & 1) {
                    ans = ans - v;
                    if (ans < 0)
                        ans += mod;
                } else {
                    ans = ans + v;
                    if (ans >= mod)
                        ans -= mod;
                }
            }
            */
            for (int j = b; j <= m; j ++) {
                int v = (long long)(pow2[(n - i) * (m - j)]) * c[i - 1][a - 1] % mod *
                                    ct[b - 1][j - 1] % mod *
                                    c[n][i] % mod *
                                    c[m][j] % mod;
                if ((i - a + j - b) & 1) {
                    ans = ans - v;
                    if (ans < 0)
                        ans += mod;
                } else {
                    ans = ans + v;
                    if (ans >= mod)
                        ans -= mod;
                }
            }
        }
        // ans = (1LL * ans * fac[n] % mod * fac[m] % mod * invfac[a - 1] % mod * invfac[b - 1] % mod);
        printf("%d\n", ans);
    }
    return 0;
}
