#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;
const long long MOD = 998244353;
int n, m, k;
long long fac[MAX], invfac[MAX];

long long qkp(long long base, long long r)
{
    long long ret = 1;
    while (r) {
        if (r & 1) {
            ret = (ret * base % MOD);
        }
        base = (base * base) % MOD;
        r >>= 1;
    }
    return ret;
}

void init()
{
    fac[0] = invfac[0] = 1;
    for (int i = 1; i < MAX; i ++) {
        fac[i] = fac[i - 1] * i % MOD;
        invfac[i] = qkp(fac[i], MOD - 2);
    }
}

long long get(int n, int m)
{
    return 1LL * fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d", &n, &m, &k);
        long long ans = 0;
        for (int i = 0; ; i ++) {
            int pick = m + k - 1 - i * n;
            //printf("i: pick: %d %d\n", i, pick);
            if (i > m) {
                break;
            }
            if (pick < m - 1) {
                break;
            }
            if (i & 1) {
                ans = (ans - (get(m, i) * get(pick, m - 1)) % MOD + MOD) % MOD;
            } else {
                ans = (ans + get(m, i) * get(pick, m - 1) % MOD) % MOD;
            }
            //printf("ans: %d\n", ans);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
