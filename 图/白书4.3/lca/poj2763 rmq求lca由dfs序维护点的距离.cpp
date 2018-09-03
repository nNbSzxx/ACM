#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1e5 + 10;

struct edge {
    int v, w, id, nt;
} e[MAX << 1];
int head[MAX], cnte;

int in[MAX], dep[MAX << 1], order[MAX << 1], idx;
// 统计边的dfs序，id -> edfn
int edfn[MAX << 1], eidx;
int st[MAX << 1][20], id[MAX << 1][20];
int tree[MAX << 1];

int n, q, s, wi[MAX];

void add(int u, int v, int w, int id)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].w = w;
    e[cnte].id = id;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

inline int lowbit(int x)
{
    return x & (-x);
}

void modify(int x, int c)
{
    for (; x <= 2 * n; x += lowbit(x)) {
        tree[x] += c;
    }
}

int query(int x)
{
    if (x == 0) {
        return 0;
    }
    int ret = 0;
    for (; x; x -= lowbit(x)) {
        ret += tree[x];
    }
    return ret;
}

void dfs(int u, int fa, int d)
{
    in[u] = ++ idx;
    dep[idx] = d;
    order[idx] = u;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        int w = e[i].w;
        int id = e[i].id;
        if (v != fa) {
            ++ eidx;
            edfn[id * 2 - 1] = eidx;
            modify(eidx, w);

            dfs(v, u, d + 1);

            ++ eidx;
            edfn[id * 2] = eidx;
            modify(eidx, -w);

            ++ idx;
            dep[idx] = d;
            order[idx] = u;
        }
    }
}

void buildst()
{
    for (int i = 1; i <= idx; i ++) {
        st[i][0] = dep[i];
        id[i][0] = order[i];
    }
    for (int j = 1; j < 20; j ++) {
        for (int i = 1; i + (1 << j) <= idx + 1; i ++) {
            int halfloc = i + (1 << (j - 1));
            if (st[i][j - 1] < st[halfloc][j - 1]) {
                st[i][j] = st[i][j - 1];
                id[i][j] = id[i][j - 1];
            } else {
                st[i][j] = st[halfloc][j - 1];
                id[i][j] = id[halfloc][j - 1];
            }
        }
    }
}

int lca(int u, int v)
{
    int l = min(in[u], in[v]);
    int r = max(in[u], in[v]);
    int k = 0;
    while (r - l + 1 >= (1 << (k + 1))) {
        ++ k;
    }
    if (st[l][k] < st[r - (1 << k) + 1][k]) {
        return id[l][k];
    } else {
        return id[r - (1 << k) + 1][k];
    }
}


int dis(int u)
{
    int x = in[u] - 1;
    return query(x);
}

int main()
{
    while (~scanf("%d%d%d", &n, &q, &s)) {
        memset(head, 0, sizeof head);
        cnte = 0;
        for (int i = 1; i < n; i ++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            wi[i] = w;
            add(u, v, w, i);
            add(v, u, w, i);
        }
        memset(tree, 0, sizeof tree);
        idx = 0;
        eidx = 0;
        dfs(1, -1, 1);

        buildst();
        //printf("%d %d\n", idx, eidx);
        while (q --) {
            int tp, u, k, w;
            scanf("%d", &tp);
            if (tp == 0) {
                scanf("%d", &u);
                int l = lca(u, s);
                //printf("%d %d %d\n", u, s, l);
                printf("%d\n", dis(u) - 2 * dis(l) + dis(s));
                s = u;
            } else {
                scanf("%d%d", &k, &w);
                int dfn = edfn[2 * k - 1];
                modify(dfn, w - wi[k]);
                dfn = edfn[2 * k];
                modify(dfn, wi[k] - w);
                wi[k] = w;
            }
        }
    }
    return 0;
}
