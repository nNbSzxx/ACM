#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int MAXN = 10010;
const int MAXM = 50010;
struct edge {
    int v, nt;
} e[MAXM], e2[MAXM];
int n, m, cnte, cnte2, cntc, idx, cntv;
int head[MAXN], head2[MAXN], dfn[MAXN], low[MAXN], color[MAXN], in[MAXN], vis[MAXN];
stack<int> s;
int cntclr[MAXN];

void init()
{
    cnte = cntc = idx = cnte2 = cntv = 0;
    memset(head, 0, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(color, 0, sizeof color);
    memset(in, 0, sizeof in);
    memset(vis, 0, sizeof vis);
    memset(cntclr, 0, sizeof cntclr);
    memset(head2, 0, sizeof head2);
}

void add(int u, int v)
{
    ++ cnte;
    e[cnte].nt = head[u];
    e[cnte].v = v;
    head[u] = cnte;
}

void add2(int u, int v)
{
    ++ cnte2;
    e2[cnte2].nt = head2[u];
    e2[cnte2].v = v;
    head2[u] = cnte2;
}

void tarjan(int u)
{
    low[u] = dfn[u] = ++ idx;
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
            ++ cntclr[cntc];
            if (now == u)
                break;
        }
    }
}

void dfs(int u)
{
    vis[u] = 1;
    ++ cntv;
    for (int i = head2[u]; i; i = e2[i].nt) {
        int v = e2[i].v;
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m)) {
        init();
        int u, v;
        for (int i = 1; i <= m; i ++) {
            // 直接反向建图，原来求缩点后出度为0的点，现在求入度为0
            // 原图判断是否所有点都能到该点，现在判断从该点能否到达所有点
            scanf("%d%d", &v, &u);
            add(u, v);
        }
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i])
                tarjan(i);
        }
        for (int u = 1; u <= n; u ++) {
            for (int i = head[u]; i; i = e[i].nt) {
                int v = e[i].v;
                if (color[u] != color[v]) {
                    in[color[v]] ++;
                    add2(color[u], color[v]);
                }
            }
        }
        int incnt = 0, in0clr = -1;
        for (int i = 1; i <= cntc; i ++) {
            if (in[i] == 0) {
                incnt ++;
                in0clr = i;
            }
        }
        if (incnt > 1) {
            puts("0");
            continue;
        }
        dfs(in0clr);
        if (cntv < cntc) {
            puts("0");
            continue;
        }
        printf("%d\n", cntclr[in0clr]);
    }

    return 0;
}
