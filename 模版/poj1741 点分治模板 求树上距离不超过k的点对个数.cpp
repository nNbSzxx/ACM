/**
 * 分治常常能把一个n的复杂度降到log n，数列上的分治常常比较好实现，但是树上怎么办呢？
 * 树上如果随便找一个点的话，可能会退化，因此需要每次从重心分割然后分治
 *
 * 本题的思路是点对
 * (1) 在同一颗子树内，是一个子问题，那么就递归求解
 * (2) 在不同子树内，需要求出每个点到重心的距离，然后合并之。
 *     考虑把所有点到重心的距离都放到一个vector里面，排好序，
 *     这样两个指针一个从头一个从尾扫一扫就能求出所有距离和小于k的点对数。
 *     不过这样会把同一棵子树的点对也算进去，需要再减出来，方法同上
 * (3) 一个在子树一个在重心，可以把重心当作一个距离重心为0的点
 *
 * 分治共log n层，每一层都需要对所有节点排序，所以总复杂度是n log^2 n的
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e4 + 10;
struct edge {
    int v, l, nt;
} e[MAX << 1];
int head[MAX], cnte;

int n, k, ans;
int centriod, censz;
int sz[MAX];
int vis[MAX]; // 标记这个点是否已经被作为重心去掉了
int dis[MAX]; // 标记这个点到其重心的距离
vector<int> disvec; // 记录点到重心的距离

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
    disvec.push_back(dis[u]);
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

/**
 * u传入重心，那么就是在计算
 * 被分割的不同子树中所有到重心距离和不超过k的点对个数（包含同一子树的）
 * 此时initDis传入0
 *
 * u传入的是重心分割后子树的根，
 * 那么就是在计算这一棵子树中所有到重心距离和不超过k的点对个数
 * 此时initDis传入重心到子树根的距离
 */
int getLessK(int u, int initDis)
{
    disvec.clear();
    dis[u] = initDis;
    getdis(u, -1);
    sort(disvec.begin(), disvec.end());

    int ret = 0;
    for (int i = 0, j = disvec.size() - 1; i < j;) {
        if (disvec[i] + disvec[j] <= k) {
            ret += j - i;
            ++ i;
        } else {
            -- j;
        }
    }
    return ret;
}

void solve(int cen)
{
    vis[cen] = 1;
    ans += getLessK(cen, 0);
    for (int i = head[cen]; i; i = e[i].nt) {
        int v = e[i].v;
        if (vis[v]) {
            continue;
        }
        // 之前算的时候会把在同一子树的点对也算进去，这是不对的，要减出来
        ans -= getLessK(v, e[i].l); // 此时已经将对应子树的size求出来了，就是sz[v]
        censz = MAX;
        getCentriod(v, cen, sz[v]);
        solve(centriod);
    }
}

int main()
{
    while (~scanf("%d%d", &n, &k), n || k) {
        memset(head, 0, sizeof head);
        cnte = 0;
        for (int i = 1; i < n; i ++) {
            int u, v, l;
            scanf("%d%d%d", &u, &v, &l);
            add(u, v, l);
            add(v, u, l);
        }
        memset(vis, 0, sizeof vis);
        censz = MAX;
        getCentriod(1, -1, n); // 获取最初重心
        ans = 0;
        solve(centriod); // 分治
        printf("%d\n", ans);
    }
    return 0;
}
