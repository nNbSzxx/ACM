#include <bits/stdc++.h>
using namespace std;
const int MAX = 2010;
struct edge {
    int v, nt;
} e[MAX];
int cost[MAX], minc[MAX];
int head[MAX], cntc, cnte, idx, n, m;
int dfn[MAX], color[MAX], low[MAX], in[MAX];
stack<int> s;
vector<int> clr[MAX];

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

void init()
{
    cntc = cnte = idx = 0;
    memset(dfn, 0, sizeof dfn);
    memset(head, 0, sizeof head);
    memset(color, 0, sizeof color);
    memset(in, 0, sizeof in);
    for (int i = 0; i < MAX; i ++) {
        clr[i].clear();
    }
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
            clr[cntc].push_back(now);
            if (now == u)
                break;
        }
    }
}

int main()
{
    //freopen("in.in", "r", stdin);
    while (~scanf("%d%d", &n, &m)) {
        init();
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &cost[i]);
        }
        int u, v;
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d", &u, &v);
            add(u, v);
        }
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i])
                tarjan(i);
        }
        int ans = 0, cntans = 0;
        for (int u = 1; u <= n; u ++) {
            for (int i = head[u]; i; i = e[i].nt) {
                v = e[i].v;
                if (color[v] != color[u]) {
                    in[color[v]] ++;
                }
            }
        }
        for (int i = 1; i <= cntc; i ++) {
            if (in[i] == 0) {
                ++ cntans;
                int minn = 0x3f3f3f3f;
                for (int u : clr[i]) {
                    if (minn > cost[u]) {
                        minn = cost[u];
                    }
                }
                ans += minn;
            }
        }
        printf("%d %d\n", cntans, ans);
    }
    return 0;
}
