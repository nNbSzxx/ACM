#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2010;
const LL MOD = 1e9 + 7;
int n, m;
LL C[maxn][maxn], xn[maxn], f[maxn];
inline void initC() {
    C[1][0] = C[1][1] = 1;
    for (int i = 2; i < maxn; ++i) {
        C[i][0] = 1;
        for (int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        C[i][i] = 1;
    }
}
inline LL quick_pow(LL a, LL b) {
    LL t = 1, y = a;
    while (b) {
        if (b & 1) t = (t * y) % MOD;
        y = (y * y) % MOD;
        b >>= 1;
    }
    return t;
}
inline void initXn() {
    xn[0] = 1;
    xn[1] = 1;
    for (int i = 2; i < maxn; ++i) xn[i] = quick_pow(i, n);
}
inline void solve() {
    LL ans = 0, t, r;
    for (int i = 1; i < m; ++i) {
        t = C[m][i] * xn[m - i] % MOD;
        r = xn[i];
        for (int j = 1; j < i; ++j) {
            r -= C[i][j] * f[j];
            if (r < 0) r = (r + MOD * MOD) % MOD;
        }
        f[i] = r;
        t = t * r % MOD;
        ans = (ans + t) % MOD;
    }
    printf("%lld\n", ans);
}
int main() {
    // freopen("in.txt", "r", stdin);
    initC();
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        initXn();
        solve();
    }
    return 0;
}
