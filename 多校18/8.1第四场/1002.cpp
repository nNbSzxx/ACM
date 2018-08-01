#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
const long long mod = 1e9 + 7;
long long fac[MAX], invfac[MAX], inv2;
long long ans[MAX], tans;
int t, size;
struct Node {
    int id, l, r;
} node[MAX];

bool cmp(const Node& n1, const Node& n2)
{
    if (n1.l / size == n2.l / size) {
        return n1.r < n2.r;
    } else {
        return n1.l < n2.l;
    }
}

long long qkp(long long base, long long r)
{
    long long ret = 1;
    while (r) {
        if (r & 1) {
            ret = (base * ret) % mod;
        }
        base = (base * base) % mod;
        r >>= 1;
    }
    return ret;
}

void init()
{
    inv2 = qkp(2, mod - 2);
    fac[0] = invfac[0] = 1;
    for (int i = 1; i < MAX; i ++) {
        fac[i] = (fac[i - 1] * i) % mod;
        invfac[i] = qkp(fac[i], mod - 2);
    }
}

long long getC(int n, int m)
{
    if (m > n) return 0LL;
    return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void subl(int l, int r)
{
    tans = (tans + getC(l, r)) * inv2 % mod;
}

void addl(int l, int r)
{
    tans = (2 * tans - getC(l, r) + mod) % mod;
}

void subr(int l, int r)
{
    tans = (tans - getC(l, r) + mod) % mod;
}

void addr(int l, int r)
{
    tans = (tans + getC(l, r)) % mod;
}

int main()
{
    init();
    scanf("%d", &t);
    size = sqrt(t);
    for (int i = 1; i <= t; i ++) {
        scanf("%d%d", &node[i].l, &node[i].r);
        node[i].id = i;
    }
    sort(node + 1, node + 1 + t, cmp);
    int l = node[1].l;
    int r = node[1].l;
    tans = qkp(2, l);
    for (int i = 1; i <= t; i ++) {
        while (l > node[i].l) {
            -- l;
            subl(l, r);

        }
        while (l < node[i].l) {
            addl(l, r);
            ++ l;
        }
        while (r > node[i].r) {

            subr(l, r);
            -- r;
        }
        while (r > node[i].r) {
            ++ r;
            addr(l, r);
        }
        ans[node[i].id] = tans;
    }
    for (int i = 1; i <= t; i ++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
