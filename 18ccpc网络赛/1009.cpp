#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
const long long MOD = 1e9 + 7;

struct edge {
   int v, w, nt;
} e[MAX << 1];
int n, cnte, head[MAX], sz[MAX];
long long ans, fac[MAX];

void init()
{
    fac[0] = 1;
    for (int i = 1; i < MAX; i ++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
}

void add(int u, int v, int w)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].w = w;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

int dfs(int x, int fa, int w)
{
    sz[x] = 1;
    for (int i = head[x]; i; i = e[i].nt) {
        int v = e[i].v;
        if (v != fa) {
            sz[x] += dfs(v, x, e[i].w);
        }
    }
    ans = (ans + 1LL * sz[x] * (n - sz[x]) % MOD * w % MOD) % MOD;
    return sz[x];
}

int main()
{
    init();
    while (~scanf("%d", &n)) {
        if (n == 1) {
            puts("0");
            continue;
        }
        cnte = 0;
        memset(head, 0, sizeof head);
        memset(sz, 0, sizeof sz);
        int u, v, w;
        for (int i = 1; i < n; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        ans = 0;
        dfs(1, 0, 0);
        ans = ans * fac[n - 2] % MOD * (n - 1) * 2 % MOD;
        printf("%lld\n", ans);
    }

    return 0;
}
