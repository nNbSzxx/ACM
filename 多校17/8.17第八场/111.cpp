#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const int MAX = 2e3 + 10;
ll c[MAX][MAX], xn[MAX], f[MAX];
int n, m;

ll p(ll base, ll r)
{
    ll ret = 1;
    while (r) {
        if (r & 1) {
            ret = ret * base % mod;
        }
        r >>= 1;
        base = base * base % mod;
    }
    return ret;
}

void initc(void)
{
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i < MAX; i ++) {
        c[i][0] = 1;
        c[i][1] = i;
        c[i][i] = 1;
        for (int j = 2; j < i; j ++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    return ;
}

void initx(void)
{
    xn[1] = 1;
    xn[0] = 0;
    for (int i = 2; i < MAX; i ++) {
        xn[i] = p(i, n);
    }
}

int main()
{
    //freopen("1011.in", "r", stdin);
    int t;
    scanf("%d", &t);
    initc();
    while (t --) {
        scanf("%d%d", &n, &m);
        initx();
        ll ans = 0;
        for (int i = 1; i < m; i ++) {
            ll temp = c[m][i] * xn[m - i] % mod;
            ll r = xn[i];
            for (int j = i - 1; j >= 1; j --) {
                r -= c[i][j] * f[j] % mod;
            }
            if (r < 0) {
                r = (r + mod * mod) % mod;
            }
            f[i] = r;
            ans = (ans + r * temp) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
