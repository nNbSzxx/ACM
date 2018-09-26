#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 3e4 + 10;

struct edge {
    int u, v, w, d, nt;
} e[MAX << 1];
int head[MAX], cnte;

int centriod, censz;
int sz[MAX];
int vis[MAX]; // 标记是否选为了重心

struct node {
    int w, d;
    bool operator<(const node& rhs) const {
        if (d != rhs.d) {
            return d < rhs.d;
        } else {
            return w > rhs.w;
        }
    }
};
node dis[MAX], disvec[MAX];
int cntd;

int n, m, ans;


void init()
{
    cnte = 0;
    memset(head, 0, sizeof head);
}

void add(int u, int v, int w, int d)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].w = w;
    e[cnte].d = d;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

void getCentriod(int u, int fa, int component)
{
    sz[u] = 1;
    int maxx = 0;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (vis[v] || v == fa) {
            continue;
        }
        getCentriod(v, u, component);
        maxx = max(maxx, sz[v]);
        sz[u] += sz[v];
    }
    maxx = max(maxx, component - sz[u]);
    if (maxx < censz) {
        censz = maxx;
        centriod = u;
    }
    return ;
}

void getsz(int u, int fa)
{
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (vis[v] || v == fa) {
            continue;
        }
        getsz(v, u);
        sz[u] += sz[v];
    }
    return ;
}

void getdis(int u, int fa)
{
    if (dis[u].d > m) {
        return ;
    }
    disvec[cntd] = dis[u];
    cntd ++;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (vis[v] || v == fa) {
            continue;
        }
        dis[v].w = dis[u].w + e[i].w;
        dis[v].d = dis[u].d + e[i].d;
        getdis(v, u);
    }
}

void eliminate(int l, int r)
{
    if (l == r) {
        return ;
    }
    int ed = l + 1;
    int lastmax = disvec[l].w;
    for (int i = l + 1; i < r; i ++) {
        if (disvec[i].w <= lastmax) {
            continue;
        }
        disvec[ed] = disvec[i];
        lastmax = disvec[i].w;
        ++ ed;
    }
    cntd = ed;
    return ;
}

void calc(int u)
{
    cntd = 0;
    disvec[cntd].w = 0;
    disvec[cntd].d = 0;
    cntd ++;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        int lasted = cntd;
        dis[v].w = e[i].w;
        dis[v].d = e[i].d;
        getdis(v, u);

        sort(disvec + lasted, disvec + cntd);
        eliminate(lasted, cntd);
        if (cntd == lasted) {
            continue;
        }
        int oldj = lasted - 1, newj = lasted;
        while (newj < cntd && oldj >= 0) {
            if (disvec[newj].d + disvec[oldj].d > m) {
                -- oldj;
            } else {
                ans = max(ans, disvec[newj].w + disvec[oldj].w);
                ++ newj;
            }
        }
        sort(disvec, disvec + cntd);
        eliminate(0, cntd);
    }
}

void solve(int cen)
{
    vis[cen] = 1;
    calc(cen);
    for (int i = head[cen]; i; i = e[i].nt) {
        int v = e[i].v;
        if (vis[v]) {
            continue;
        }
        getsz(v, cen);
        censz = MAX;
        getCentriod(v, cen, sz[v]);
        solve(centriod);
    }
}

int main()
{
    int t, tc = 1;
    scanf("%d", &t);
    while (t --) {
        init();
        scanf("%d%d", &n, &m);
        for (int i = 1; i < n; i ++) {
            int u, v, w, d;
            scanf("%d%d%d%d", &u, &v, &d, &w);
            add(u, v, w, d);
            add(v, u, w, d);
        }
        memset(vis, 0, sizeof vis);
        censz = MAX;
        getCentriod(1, -1, n);
        ans = 0;
        solve(centriod);
        printf("Case %d: %d\n", tc ++, ans);
    }
    return 0;
}
