#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int MAXN = 2e3 + 10;
const int MAXM = 4e6 + 10;

struct edge {
    int v, nt;
} e[MAXM];
int head[MAXN], cnte;
int dfn[MAXN], low[MAXN], idx, color[MAXN], cntc;
stack<int> s;
int n, m;

void add(int h[MAXN], edge ed[MAXM], int &cnt, int u, int v)
{
    ++ cnt;
    ed[cnt].v = v;
    ed[cnt].nt = h[u];
    h[u] = cnt;
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
            int now = s.top();
            s.pop();
            color[now] = cntc;
            if (now == u) {
                break;
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= m; i ++) {
            int a, b, c;
            char op[20];
            scanf("%d%d%d %s", &a, &b, &c, op);
            if (!strcmp(op, "OR")) {
                if (c == 1) {
                    // a or b = 1, !a => b, !b => a
                    add(head, e, cnte, a + n, b);
                    add(head, e, cnte, b + n, a);
                } else {
                    // a or b = 0, !a && !b
                    add(head, e, cnte, a, a + n);
                    add(head, e, cnte, b, b + n);
                }
            } else if (!strcmp(op, "AND")) {
                if (c == 1) {
                    // a and b = 1, a && b
                    add(head, e, cnte, a + n, a);
                    add(head, e, cnte, b + n, b);
                } else {
                    // a and b = 0, !a or !b = 1, a => !b, b => !a
                    add(head, e, cnte, a, b + n);
                    add(head, e, cnte, b, a + n);
                }
            } else {
                if (c == 1) {
                    // a xor b = 1, a => !b, b => !a, !a => b, !b => a
                    add(head, e, cnte, a, b + n);
                    add(head, e, cnte, b, a + n);
                    add(head, e, cnte, a + n, b);
                    add(head, e, cnte, b + n, a);
                } else {
                    // a xor b = 0, a => b, b => a, !a => !b, !b => !a
                    add(head, e, cnte, a, b);
                    add(head, e, cnte, b, a);
                    add(head, e, cnte, a + n, b + n);
                    add(head, e, cnte, b + n, a + n);
                }
            }
        }
        memset(dfn, 0, sizeof dfn);
        idx = 0;
        cntc = 0;
        for (int i = 0; i < 2 * n; i ++) {
            if (!dfn[i]) {
                tarjan(i);
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i ++) {
            if (color[i] == color[i + n]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
