#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;
const int MAXN = 10010;
const int MAXM = 50010;

struct edge {
    int v, nt;
} e[MAXM];
int head[MAXN], cnte;
int dfn[MAXN], low[MAXN], idx, color[MAXN], cntc;
int cnum[MAXN];
stack<int> s;
int indeg[MAXN], vis[MAXN];
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
    if (dfn[u] == low[u]) {
        ++ cntc;
        while (true) {
            int now = s.top();
            s.pop();
            color[now] = cntc;
            cnum[cntc] ++;
            if (now == u) {
                break;
            }
        }
    }
}

void dfs(int u)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (!vis[v]) {
            dfs(v);
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
            add(v, u);
        }
        memset(dfn, 0, sizeof dfn);
        idx = 0;
        memset(color, 0, sizeof color);
        cntc = 0;
        memset(cnum, 0, sizeof cnum);
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i]) {
                tarjan(i);
            }
        }

        memset(indeg, 0, sizeof indeg);
        for (int u = 1; u <= n; u ++) {
            for (int i = head[u]; i; i = e[i].nt) {
                if (color[e[i].v] != color[u])
                    indeg[color[e[i].v]] ++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= cntc; i ++) {
            if (indeg[i] == 0) {
                memset(vis, 0, sizeof vis);
                for (int j = 1; j <= n; j ++) {
                    if (color[j] == i) {
                        dfs(j);
                        break;
                    }
                }
                ans = cnum[i];
                for (int j = 1; j <= n; j ++) {
                    if (!vis[j]) {
                        ans = 0;
                        break;
                    }
                }
                break;
            }
        }
        printf("%d\n", ans);

    }

    return 0;
}
