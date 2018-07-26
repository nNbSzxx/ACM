#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010;
const int MAXM = 100010;
const int INF = 0x3f3f3f3f;
struct edge {
    int v, w, nt;
} e[MAXM];
int n, m, cntc, cnte, idx, dfn[MAXN], low[MAXN];
int color[MAXN], head[MAXN];
int minc[MAXN], ans;
stack<int> s;

void init()
{
    ans = 0;
    cntc = cnte = idx = 0;
    memset(head, 0, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(color, 0, sizeof color);
}

void add(int u, int v, int w)
{
    cnte ++;
    e[cnte].v = v;
    e[cnte].w = w;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ idx;
    s.push(u);
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!color[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++ cntc;
        while (true) {
            int now = s.top(); s.pop();
            color[now] = cntc;
            if (now == u)
                break;
        }
    }
}

void build()
{
    //printf("color: %d\n", cntc);
    //for (int i = 1; i <= n; i ++) {
    //    printf("%d %d\n", i, color[i]);
    //}
    for (int i = 1; i <= cntc; i ++) {
        minc[i] = INF;
    }
    for (int u = 1; u <= n; u ++) {
        for (int i = head[u]; i; i = e[i].nt) {
            int v = e[i].v;
            if (color[v] != color[u]) {
                minc[color[v]] = min(minc[color[v]], e[i].w);
            }
        }
    }
    for (int i = 1; i <= cntc; i ++) {
        if (color[1] != i)
            ans += minc[i];
    }
}

int main()
{
    //freopen("in.in", "r", stdin);
    while (~scanf("%d%d", &n, &m)) {
        init();
        int u, v, w;
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            add(u + 1, v + 1, w);
        }
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i])
                tarjan(i);
        }
        build();
        printf("%d\n", ans);
    }
    return 0;
}
