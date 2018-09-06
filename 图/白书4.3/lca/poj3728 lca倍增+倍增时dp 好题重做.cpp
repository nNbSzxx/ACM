#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 5e4 + 10;
const int MAXH = 18;

struct edge {
    int v, nt;
} e[MAX << 1];
int head[MAX], cnte;
int anc[MAX][MAXH], dep[MAX];
queue<int> q;

int w[MAX];
int maxval[MAX][MAXH], minval[MAX][MAXH];
int upval[MAX][MAXH], downval[MAX][MAXH];

int n, qry;
int curupmin, curdownmin, curupmax, curdownmax;
int curupval, curdownval;

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

void bfs(int root)
{
    dep[root] = 1;
    for (int i = 0; i < MAXH; i ++) {
        anc[root][i] = root;
        maxval[root][i] = w[root];
        minval[root][i] = w[root];
        upval[root][i] = 0;
        downval[root][i] = 0;
    }
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nt) {
            int v = e[i].v;
            if (v == anc[u][0]) continue;
            dep[v] = dep[u] + 1;
            anc[v][0] = u;
            maxval[v][0] = max(w[u], w[v]);
            minval[v][0] = min(w[u], w[v]);
            upval[v][0] = max(0, w[u] - w[v]);
            downval[v][0] = max(0, w[v] - w[u]);
            for (int j = 1; j < MAXH; j ++) {
                int halfanc = anc[v][j - 1];
                anc[v][j] = anc[halfanc][j - 1];
                maxval[v][j] = max(maxval[v][j - 1], maxval[halfanc][j - 1]);
                minval[v][j] = min(minval[v][j - 1], minval[halfanc][j - 1]);
                upval[v][j] = max(max(upval[v][j - 1], upval[halfanc][j - 1]),
                                  maxval[halfanc][j - 1] - minval[v][j - 1]);
                downval[v][j] = max(max(downval[v][j - 1], downval[halfanc][j - 1]),
                                    maxval[v][j - 1] - minval[halfanc][j - 1]);
            }
            q.push(v);
        }
    }
}

void update(int x, int h, int id)
{
    if (id == 0) {
        curupval = max(max(curupval, upval[x][h]), maxval[x][h] - curupmin);
        curupmax = max(curupmax, maxval[x][h]);
        curupmin = min(curupmin, minval[x][h]);
    } else {
        curdownval = max(max(curdownval, downval[x][h]), curdownmax - minval[x][h]);
        curdownmax = max(curdownmax, maxval[x][h]);
        curdownmin = min(curdownmin, minval[x][h]);
    }
}

int swim(int x, int h, int id)
{
    int ret = x;
    for (int i = 0; h; i ++, h >>= 1) {
        if (h & 1) {
            update(ret, i, id);
            ret = anc[ret][i];
        }
    }
    return ret;
}

int lca(int x, int y)
{
    curupmax = w[x];
    curupmin = w[x];
    curupval = 0;
    curdownmax = w[y];
    curdownmin = w[y];
    curdownval = 0;
    if (dep[x] > dep[y]) {
        x = swim(x, dep[x] - dep[y], 0);
    } else {
        y = swim(y, dep[y] - dep[x], 1);
    }
    if (x == y) {
        return max(max(curupval, curdownval), curdownmax - curupmin);
    }
    for (int i = MAXH - 1; i >= 0; i --) {
        if (anc[x][i] != anc[y][i]) {
            update(x, i, 0);
            x = anc[x][i];
            update(y, i, 1);
            y = anc[y][i];
        }
    }
    update(x, 0, 0);
    update(y, 0, 1);
    return max(max(curupval, curdownval), curdownmax - curupmin);
}

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &w[i]);
        }
        memset(head, 0, sizeof head);
        cnte = 0;
        for (int i = 1; i < n; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        bfs(1);
        scanf("%d", &qry);
        while (qry --) {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", lca(u, v));
        }
    }


    return 0;
}
