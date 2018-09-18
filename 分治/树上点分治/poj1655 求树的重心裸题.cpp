/**
 * 题意是求重心，以及去掉重心后剩下的最大的子树的size
 * 如果有多个重心，则求编号最小的那个
 * 求重心是点分治的前置技能，一遍dfs即可
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2e4 + 10;
struct edge {
    int v, nt;
} e[MAX << 1];
int head[MAX], cnte;

int n;
int sz[MAX];
int centriod, censz;

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

void getCentroid(int u, int fa, int component)
{
    sz[u] = 1;
    int maxx = 0; // 记录最大的子树的size
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (v == fa) {
            continue;
        }
        getCentroid(v, u, component);
        sz[u] += sz[v];
        maxx = max(maxx, sz[v]);
    }
    maxx = max(maxx, component - sz[u]);
    // 所有节点中，最大子树的size最小的，就是重心
    if (maxx < censz || (maxx == censz && u < centriod)) {
        censz = maxx;
        centriod = u;
    }
    return ;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        memset(head, 0, sizeof head);
        cnte = 0;
        for (int i = 1; i < n; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        censz = MAX;
        getCentroid(1, -1, n);
        printf("%d %d\n", centriod, censz);
    }

    return 0;
}
