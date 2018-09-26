/**
 * 对于查询的点来说，离它最近的白点要么在重心分割后的自己这棵子树上，
 * 要么在其他子树上
 * 这时如果知道离重心最近的白点在哪里，那么就解决了在其他子树上的情况（就这个白点）
 * 否则在自己这棵树上，再次重心分割，则面临相同子问题
 * 综上，预处理出所有重心，在每个重心上维护分割出来子树上离它最近的白点，
 * 由于带删除，所以可以用堆维护
 * 对于每次查询，对每次重心分割（有点像一维的二分）后的重心组成的链进行查询
 * 用lca维护树上两点距离
 * 重心链最长logn，在线lca也是logn的，所以每次查询是loglog的复杂度，
 * 预处理重心是nlogn的
 *
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct edge {
    int v, nt;
} e[MAX << 1];
int head[MAX], cnte;

int vis[MAX];
int sz[MAX];
int centriod, censz;
int cenfa[MAX];

struct node {
    int id;
    int dis;
    node() {}
    node(int idd, int diss) : id(idd), dis(diss) {}
    bool operator<(const node& rhs) const {
        return dis > rhs.dis;
    }
};
priority_queue<node> q[MAX];

int n, qy;
int white[MAX];

const int MAXH = 19;
queue<int> aq;
int dep[MAX], anc[MAX][MAXH];

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

void init()
{
    for (int i = 1; i <= n; i ++) {
        while (!q[i].empty()) {
            q[i].pop();
        }
    }
    cnte = 0;
    memset(head, 0, sizeof head);
    memset(white, 0, sizeof white);
    memset(vis, 0, sizeof vis);
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

void getsize(int u, int fa)
{
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (v == fa || vis[v]) {
            continue;
        }
        getsize(v, u);
        sz[u] += sz[v];
    }
    return ;
}

void initCentroid(int cen)
{
    vis[cen] = 1;
    for (int i = head[cen]; i; i = e[i].nt) {
        int v = e[i].v;
        if (vis[v]) {
            continue;
        }
        getsize(v, cen);
        censz = MAX;
        getCentriod(v, cen, sz[v]);
        cenfa[centriod] = cen;
        initCentroid(centriod);
    }
}

void bfs(int root)
{
    dep[root] = 1;
    aq.push(root);
    for (int i = 0; i < MAXH; i ++) {
        anc[root][i] = root;
    }
    while (!aq.empty()) {
        int u = aq.front();
        aq.pop();
        for (int i = head[u]; i; i = e[i].nt) {
            int v = e[i].v;
            if (v == anc[u][0]) {
                continue;
            }
            anc[v][0] = u;
            dep[v] = dep[u] + 1;
            for (int i = 1; i < MAXH; i ++) {
                anc[v][i] = anc[anc[v][i - 1]][i - 1];
            }
            aq.push(v);
        }
    }
}

int swim(int x, int h)
{
    int ret = x;
    for (int i = 0; h; i ++, h >>= 1) {
        if (h & 1) {
            ret = anc[ret][i];
        }
    }
    return ret;
}

int lca(int x, int y)
{
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    x = swim(x, dep[x] - dep[y]);
    if (x == y) {
        return x;
    }
    for (int i = MAXH - 1; i >= 0; i --) {
        if (anc[x][i] != anc[y][i]) {
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return anc[x][0];
}

int getdis(int u, int v)
{
    return dep[u] - dep[lca(u, v)] * 2 + dep[v];
}

int calc(int ori)
{
    int ans = INF;
    int x = ori;
    while (x != -1) {
        //printf("%d\n", x);
        while (!q[x].empty()) {
            int id = q[x].top().id;
            if (!white[id]) {
                q[x].pop();
            } else {
                break;
            }
        }
        if (!q[x].empty()) {
            int id = q[x].top().id;
            ans = min(ans, getdis(id, ori));
        }
        x = cenfa[x];
    }
    return (ans == INF) ? -1 : ans;
}

int main()
{
    while (~scanf("%d", &n)) {
        init();
        for (int i = 1; i < n; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        censz = MAX;
        getCentriod(1, -1, n);
        //puts("!!!!!!!!");
        cenfa[centriod] = -1;
        initCentroid(centriod);
        scanf("%d", &qy);
        while (qy --) {
            int op, id;
            scanf("%d%d", &op, &id);
            if (op == 0) {
                white[id] ^= 1;
                if (white[id]) {
                    int x = id;
                    while (x != -1) {
                        q[x].push(node(id, getdis(id, x)));
                        x = cenfa[x];
                    }
                }
            } else {
                printf("%d\n", calc(id));
            }
        }
    }
    return 0;
}





