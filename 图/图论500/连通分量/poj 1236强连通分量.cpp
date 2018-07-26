#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXN = 110;
const int MAXM = MAXN * MAXN;
struct edge {
    int v, nt;
} e[MAXM];
int head[MAXN], low[MAXN], dfn[MAXN], in[MAXN], out[MAXN], color[MAXN];
int cnte, cntc, idx, n;
stack<int> s;

void init()
{
    cnte = cntc = idx = 0;
    memset(head, 0, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(color, 0, sizeof color);
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
}

void add (int u, int v)
{
    cnte ++;
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
            int now = s.top(); s.pop();
            color[now] = cntc;
            if (now == u) {
                break;
            }
        }
    }
}

int main()
{
    while (~scanf("%d", &n)) {
        init();
        for (int i = 1; i <= n; i ++) {
            int v;
            while (scanf("%d", &v), v) {
                add(i, v);
            }
        }
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i]) {
                tarjan(i);
            }
        }

        for (int u = 1; u <= n; u ++) {
            for (int i = head[u]; i; i = e[i].nt) {
                int v = e[i].v;
                if (color[u] != color[v]) {
                    in[color[v]] ++;
                    out[color[u]] ++;
                }
            }
        }
        int in0 = 0, out0 = 0;
        for (int i = 1; i <= cntc; i ++) {
            if (in[i] == 0) ++ in0;
            if (out[i] == 0) ++ out0;
        }
        printf("%d\n", in0);
        if (cntc == 1) {
            puts("0");
        } else {
            printf("%d\n", max(in0, out0));
        }

    }
    return 0;
}
