#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;

struct edge {
    int v, nt;
} e[MAX << 1];
int head[MAX], cnte;

int n;
int cntodd = 0;
int sz[MAX];

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

void dfs(int x, int fa, int d)
{
    if (d) {
        cntodd ++;
    }
    sz[x] = 1;
    for (int i = head[x]; i; i = e[i].nt) {
        int v = e[i].v;
        if (v == fa) continue;
        dfs(v, x, d ^ 1);
        sz[x] += sz[v];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(1, 0, 0);
    long long ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += 1LL * sz[i] * (n - sz[i]);
    }
    ans += 1LL * cntodd * (n - cntodd);
    printf("%lld\n", ans / 2);
    return 0;
}
