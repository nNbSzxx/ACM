#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 50010;
const int MAXH = 18;
struct edge {
    int v, nt;
} e[MAX << 1];
int head[MAX], dep[MAX], anc[MAX][MAXH];
int maxx[MAX][MAXH], minn[MAX][MAXH];
int upval[MAX][MAXH], downval[MAX][MAXH], val[MAX];
int cnte, n, qy;
int curupmin, curdownmax, curupval, curdownval;
queue<int> q;

void init()
{
    cnte = 0;
    memset(head, 0, sizeof head);
}

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

void bfs(int root)
{
    q.push(root);
    dep[root] = 1;
    for (int i = 0; i < MAXH; i ++) {
        anc[root][i] = root;
        minn[root][i] = val[root];
        maxx[root][i] = val[root];
        upval[root][i] = 0;
        downval[root][i] = 0;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nt) {
            int v = e[i].v;
            if (v != anc[u][0]) {
                dep[v] = dep[u] + 1;
                anc[v][0] = u;
                q.push(v);
                minn[v][0] = min(val[v], val[u]);
                maxx[v][0] = max(val[v], val[u]);
                upval[v][0] = val[u] - val[v];
                downval[v][0] = val[v] - val[u];
                for (int i = 1; i < MAXH; i ++) {
                    anc[v][i] = anc[anc[v][i - 1]][i - 1];
                    minn[v][i] = min(minn[v][i - 1], minn[anc[v][i - 1]][i - 1]);
                    maxx[v][i] = max(maxx[v][i - 1], maxx[anc[v][i - 1]][i - 1]);
                    upval[v][i] = max(max(upval[v][i - 1], upval[anc[v][i - 1]][i - 1]),
                                      maxx[anc[v][i - 1]][i - 1] - minn[v][i - 1]);
                    downval[v][i] = max(max(downval[v][i - 1], downval[anc[v][i - 1]][i - 1]),
                                        maxx[v][i - 1] - minn[anc[v][i - 1]][i - 1]);
                }
            }
        }
    }
}

void swim(int& x, int& y)
{
    if (dep[x] == dep[y]) return ;
    if (dep[x] > dep[y]) {
        int h = dep[x] - dep[y];
        for (int i = 0; h; i ++, h >>= 1) {
            if (h & 1) {
                curupval = max(max(curupval, upval[x][i]), maxx[x][i] - curupmin);
                curupmin = min(curupmin, minn[x][i]);
                x = anc[x][i];
            }
        }
    }
    if (dep[x] < dep[y]) {
        int h = dep[y] - dep[x];
        for (int i = 0; h; i ++, h >>= 1) {
            if (h & 1) {
                curdownval = max(max(curdownval, downval[y][i]), curdownmax - minn[y][i]);
                curdownmax = max(curdownmax, maxx[y][i]);
                y = anc[y][i];
            }
        }
    }
}

int solve(int x, int y)
{
    //printf("lca x, y, lca: %d %d", x, y);
    curupval = 0;
    curdownval = 0;
    curupmin = val[x];
    curdownmax = val[y];
    swim(x, y);
    if (x == y) {
        //printf(" %d\n", x);
        return max(max(curupval, curdownval), curdownmax - curupmin);
    }
    for (int i = MAXH - 1; i >= 0; i --) {
        if (anc[x][i] != anc[y][i]) {
            curupval = max(max(curupval, upval[x][i]), maxx[x][i] - curupmin);
            curupmin = min(curupmin, minn[x][i]);
            curdownval = max(max(curdownval, downval[y][i]), curdownmax - minn[y][i]);
            curdownmax = max(curdownmax, maxx[y][i]);
            x = anc[x][i];
            y = anc[y][i];
        }
    }

    //printf(" %d\n", anc[x][0]);

    curupval = max(max(curupval, upval[x][0]), maxx[x][0] - curupmin);
    curupmin = min(curupmin, minn[x][0]);
    curdownval = max(max(curdownval, downval[y][0]), curdownmax - minn[y][0]);
    curdownmax = max(curdownmax, maxx[y][0]);

    return max(max(curupval, curdownval), curdownmax - curupmin);
}

int main()
{
    //freopen("in.in", "r", stdin);
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &val[i]);
        }
        for (int i = 1; i < n; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        bfs(1);
        scanf("%d", &qy);
        while (qy --) {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", solve(u, v));
        }
    }

    return 0;
}

