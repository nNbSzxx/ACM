#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e4 + 10;
const int MAXK = 1e7 + 10;
struct edge {
    int v, l, nt;
} e[MAX << 1];
int head[MAX], cnte;

int n, m, ans;
int centriod, censz;
int sz[MAX];
int k[105], ok[105];
int vis[MAX]; // 标记这个点是否已经被作为重心去掉了
int dis[MAX]; // 标记这个点到其重心的距离
int sum[MAXK]; // 标记当前是否有到中心距离为i的点
vector<int> disvec;

void add(int u, int v, int l)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].l = l;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

// 求重心
void getCentriod(int u, int fa, int component)
{
    sz[u] = 1;
    int maxx = 0;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (v == fa || vis[v]) {
            continue;
        }
        getCentriod(v, u, component);
        sz[u] += sz[v];
        maxx = max(maxx, sz[v]);
    }
    maxx = max(maxx, component - sz[u]);
    if (maxx < censz) {
        censz = maxx;
        centriod = u;
    }
    return ;
}

// 求各个点到重心的距离
void getdis(int u, int fa)
{
    disvec.push_back(dis[u]);
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (vis[v] || v == fa) {
            continue;
        }
        dis[v] = dis[u] + e[i].l;
        getdis(v, u);
    }
    return ;
}

void check(int u)
{
    vector<int> cur;
    sum[0] = 1;
    for (int i = head[u]; i; i = e[i].nt) {
        disvec.clear();
        int v = e[i].v;
        dis[v] = e[i].l;
        getdis(v, -1);
        for (int j = 1; j <= m; j ++) {
            for (auto a : disvec) {
                if (a <= k[j]) {
                    ok[j] |= sum[k[j] - a];
                }
            }
        }
        cur.insert(cur.end(), disvec.begin(), disvec.end());
        for (auto a : disvec) {
            sum[a] = 1;
        }
    }
    for (auto b : cur) {
        sum[b] = 0;
    }
}

void solve(int cen)
{
    vis[cen] = 1;
    check(cen);
    for (int i = head[cen]; i; i = e[i].nt) {
        int v = e[i].v;
        if (vis[v]) {
            continue;
        }

        censz = MAX;
        getCentriod(v, cen, sz[v]);
        solve(centriod);
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        memset(head, 0, sizeof head);
        memset(ok, 0, sizeof ok);
        cnte = 0;
        for (int i = 1; i < n; i ++) {
            int u, v, l;
            scanf("%d%d%d", &u, &v, &l);
            add(u, v, l);
            add(v, u, l);
        }
        for (int i = 1; i <= m; i ++) {
            scanf("%d", &k[i]);
        }
        memset(vis, 0, sizeof vis);
        censz = MAX;
        getCentriod(1, -1, n); // 获取最初重心
        ans = 0;
        solve(centriod); // 分治
        for (int i = 1; i <= m; i ++) {
            if (ok[i]) {
                puts("AYE");
            } else {
                puts("NAY");
            }
        }
    }
    return 0;
}
