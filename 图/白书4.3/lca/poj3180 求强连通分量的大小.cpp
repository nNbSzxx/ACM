#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 5e4 + 10;

struct edge {
    int v, nt;
} e[MAXM];
int head[MAXN], cnte;
int dfn[MAXN], low[MAXN], idx, color[MAXN], cntc, csz[MAXN];
stack<int> s;
int n, m;

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
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
        csz[cntc] = 0;
        while (true) {
            int now = s.top();
            s.pop();
            color[now] = cntc;
            csz[cntc] ++;
            if (now == u) {
                break;
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        memset(head, 0, sizeof head);
        cnte = 0;
        for (int i = 1; i <= m; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
        }
        memset(dfn, 0, sizeof dfn);
        idx = 0;
        cntc = 0;

        for (int i = 1; i <= n; i ++) {
            if (!dfn[i]) {
                tarjan(i);
            }
        }
        int ans = 0;
        for (int i = 1; i <= cntc; i ++) {
            if (csz[i] > 1) {
                ++ ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
