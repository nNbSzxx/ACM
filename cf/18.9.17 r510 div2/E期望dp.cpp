#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1010;
const long long MOD = 998244353;


int n, m;
long long dp[MAX * MAX];
long long sumdp[MAX * MAX];
long long sumr2[MAX * MAX], sumr[MAX * MAX];
long long sumc2[MAX * MAX], sumc[MAX * MAX];
long long inv[MAX * MAX];

struct node {
    int x, y;
    int a;
} a[MAX * MAX];

void init()
{
    inv[1] = 1;
    for(int i = 2; i < MAX * MAX; i ++)
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
}

bool cmp(const node& a1, const node& a2)
{
    return a1.a < a2.a;
}

long long qkp(long long base, long long r)
{
    long long ret = 1;
    while (r) {
        if (r & 1) {
            ret = (ret * base) % MOD;
        }
        r >>= 1;
        base = (base * base) % MOD;
    }
    return ret;
}

int main()
{
    init();
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            ++ cnt;
            scanf("%d", &a[cnt].a);
            a[cnt].x = i;
            a[cnt].y = j;
        }
    }
    int xx, yy;
    scanf("%d%d", &xx, &yy);
    sort(a + 1, a + 1 + n * m, cmp);

    cnt = 0;
    long long accdp = 0;
    long long accr2 = 0, accr = 0;
    long long accc2 = 0, accc = 0;
    int accid = 0;
    int curid = 0;
    long long ans;

    a[n * m + 1].a = -1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            ++ cnt;
            dp[cnt] = ((sumdp[cnt - 1] + sumr2[cnt - 1] + sumc2[cnt - 1] -
                       2 * a[cnt].x * sumr[cnt - 1] - 2 * a[cnt].y * sumc[cnt - 1]) % MOD + MOD) * inv[curid] % MOD;
            if (curid != 0)
                dp[cnt] = (dp[cnt] + a[cnt].x * a[cnt].x + a[cnt].y * a[cnt].y) % MOD;
            if (a[cnt].x == xx && a[cnt].y == yy) {
                ans = dp[cnt];
                break;
            }
            sumdp[cnt] = sumdp[cnt - 1];
            sumr2[cnt] = sumr2[cnt - 1];
            sumr[cnt] = sumr[cnt - 1];
            sumc2[cnt] = sumc2[cnt - 1];
            sumc[cnt] = sumc[cnt - 1];

            ++ accid;
            accdp = (accdp + dp[cnt]) % MOD;
            accr2 = (accr2 + a[cnt].x * a[cnt].x) % MOD;
            accc2 = (accc2 + a[cnt].y * a[cnt].y) % MOD;
            accr = (accr + a[cnt].x) % MOD;
            accc = (accc + a[cnt].y) % MOD;

            if (a[cnt].a != a[cnt + 1].a) {
                curid += accid;
                sumdp[cnt] = (sumdp[cnt] + accdp) % MOD;
                sumr2[cnt] = (sumr2[cnt] + accr2) % MOD;
                sumc2[cnt] = (sumc2[cnt] + accc2) % MOD;
                sumr[cnt] = (sumr[cnt] + accr) % MOD;
                sumc[cnt] = (sumc[cnt] + accc) % MOD;
                accid = accdp = accr2 = accc2 = accr = accc = 0;
            }
            //printf("%d %lld %lld %lld %lld %lld\n", curid, sumdp[cnt], sumr2[cnt], sumc2[cnt], sumr[cnt], sumc[cnt]);
        }
    }
    //puts("");
    printf("%lld\n", ans);
    //for (int i = 1; i <= 4; i ++) {
    //    printf("%lld ", dp[i]);
    //}
    return 0;
}
