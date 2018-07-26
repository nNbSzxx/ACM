#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 5010;
const int MAXM = MAXN * MAXN;
struct edge {
    int v, nt;
} e[MAXM];
int head[MAXN], dfn[MAXN], low[MAXN], color[MAXN], out[MAXN];
int n, m, cnte, cntc, idx, ans[MAXN], cntans;
stack<int> s;
vector<int> clr[MAXN];

void init()
{
    cnte = cntc = idx = cntans = 0;
    for (int i = 0; i < MAXN; i ++) {
        clr[i].clear();
    }
    memset(head, 0, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(color, 0, sizeof color);
    memset(out, 0, sizeof out);
}

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
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
            clr[cntc].push_back(now);
            if (u == now) {
                break;
            }
        }

    }
}

int main()
{
    while (~scanf("%d", &n), n) {
        init();
        int u, v;
        scanf("%d", &m);
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d", &u, &v);
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
                    out[color[u]] ++;
                }
            }
        }
        for (int i = 1; i <= cntc; i ++) {
            if (out[i] == 0) {
                for (int j = 0; j < clr[i].size(); ++ j) {
                    ans[cntans ++] = clr[i][j];
                }
            }
        }
        sort(ans, ans + cntans);
        printf("%d", ans[0]);
        for (int i = 1; i < cntans; i ++) {
            printf(" %d", ans[i]);
        }
        puts("");
    }
    return 0;
}
