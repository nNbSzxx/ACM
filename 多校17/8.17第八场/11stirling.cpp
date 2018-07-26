#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const int MAX = 2e3 + 10;
ll c[MAX][MAX], s[MAX][MAX], xn[MAX], fac[MAX];
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
void inits(void)
{
    s[0][0] = 0;
    s[1][0] = 0;
    s[1][1] = 1;
    for (int i = 2; i < MAX; i ++) {
        s[i][0] = 0;
        s[i][1] = 1;
        s[i][i] = 1;
        for (int j = 2; j < i; j ++) {
            s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % mod;
        }
    }
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

void initf(void)
{
    fac[0] = fac[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        fac[i] = i * fac[i - 1] % mod;
    }
}
int main()
{
    int t;
    inits();
    initc();
    initf();
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        initx();
        ll ans = 0;
        for (int i = 1; i < m && i <= n; i ++) {
            ans = (ans + c[m][i] * s[n][i] % mod * fac[i] % mod * xn[m - i]) % mod;
            //cout << c[m][i] << " " << s[n][i] << " " << fac[i] << " " << xn[m - i] << endl;
        }
        printf("%lld\n", ans);
    }
}
