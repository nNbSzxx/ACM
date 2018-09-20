#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
const int MAX = 100010;

struct edge {
    int v, nt, used;
} e[MAX << 2];
int n, m, q, cnte, idx, cntb;
int head[MAX], dfn[MAX], low[MAX];
int isbridge[MAX], father[MAX];

void init()
{
    father[1] = cnte = idx = cntb = 0;
    memset(head, -1, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(isbridge, 0, sizeof isbridge);
}

void add(int u, int v)
{
    e[cnte].v = v;
    e[cnte].nt = head[u];
    e[cnte].used = 0;
    head[u] = cnte;
    ++ cnte;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ idx;
    for (int i = head[u]; i != -1; i = e[i].nt) {
        if (e[i].used)
            continue;
        e[i].used = 1;
        e[i ^ 1].used = 1;
        int v = e[i].v;
        if (!dfn[v]) {
            father[v] = u;
            tarjan(v);
            if (low[v] > dfn[u]) {
                // v无法通过回边或者通过子女到达比u点更靠前的点，
                // 那么我们只需要标记v点即可表明割边（桥）
                // 桥就是u到v的这条边
                isbridge[v] = 1;
                ++ cntb;
            }
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void lca(int u, int v)
{
    while (u != v) {
        while (dfn[u] > dfn[v]) {
            if (isbridge[u]) {
                isbridge[u] = 0;
                -- cntb;
            }
            u = father[u];
        }
        while (dfn[v] > dfn[u]) {
            if (isbridge[v]) {
                isbridge[v] = 0;
                -- cntb;
            }
            v = father[v];
        }
    }
    //printf("lca : %d\n", u);
}

int main()
{
    int tc = 1;
    while (~scanf("%d%d", &n, &m), n || m) {
        init();
        int u, v;
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }

        tarjan(1);

        scanf("%d", &q);
        printf("Case %d:\n", tc ++);
        while (q --) {
            int u, v;
            scanf("%d%d", &u, &v);
            lca(u, v);
            printf("%d\n", cntb);
        }
        puts("");
    }

    return 0;
}
