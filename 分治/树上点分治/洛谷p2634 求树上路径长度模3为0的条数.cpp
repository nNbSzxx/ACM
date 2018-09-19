#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 2e4 + 10;
struct edge {
    int v, l, nt;
} e[MAX << 1];
int head[MAX], cnte;

int n, ans;
int centriod, censz;
int sz[MAX];
int vis[MAX]; // 标记这个点是否已经被作为重心去掉了
int dis[MAX]; // 标记这个点到其重心的距离
int dis3[3]; // 记录dis模3后的条数

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

// 求各个点到重心的距离，同时求重心分割后各个子树的size
void getdis(int u, int fa)
{
    dis3[dis[u] % 3] ++;
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (vis[v] || v == fa) {
            continue;
        }
        dis[v] = dis[u] + e[i].l;
        getdis(v, u);
        sz[u] += sz[v];
    }
    return ;
}

int get3(int u, int initDis)
{
    dis[u] = initDis % 3;
    dis3[0] = dis3[1] = dis3[2] = 0;
    getdis(u, -1);

    int ret = 0;
    ret += dis3[0] * dis3[0];
    ret += 2 * dis3[1] * dis3[2];
    return ret;
}

void solve(int cen)
{
    vis[cen] = 1;
    ans += get3(cen, 0);
    for (int i = head[cen]; i; i = e[i].nt) {
        int v = e[i].v;
        if (vis[v]) {
            continue;
        }
        // 之前算的时候会把在同一子树的点对也算进去，这是不对的，要减出来
        ans -= get3(v, e[i].l); // 此时已经将对应子树的size求出来了，就是sz[v]
        censz = MAX;
        getCentriod(v, cen, sz[v]);
        solve(centriod);
    }
}

int main()
{
    while (~scanf("%d", &n)) {
        memset(head, 0, sizeof head);
        cnte = 0;
        for (int i = 1; i < n; i ++) {
            int u, v, l;
            scanf("%d%d%d", &u, &v, &l);
            l %= 3;
            add(u, v, l);
            add(v, u, l);
        }
        memset(vis, 0, sizeof vis);
        censz = MAX;
        getCentriod(1, -1, n); // 获取最初重心
        ans = 0;
        solve(centriod); // 分治
        int g = __gcd(ans, n * n);
        printf("%d/%d\n", ans / g, n * n / g);
    }
    return 0;
}
