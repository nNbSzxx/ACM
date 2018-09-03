/**
 *  通过记录dfs序，找到lca
 *  思想是找u和v的lca，手动模拟dfs可以发现，lca一定在dfs的路线上
 *  而在这个区间中，lca一定是深度最小的那个
 *  因此，可以维护区间最小值，O(log n)处理一个请求
 *  预处理的时间是O(n log n)的
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e4 + 10;

struct edge {
	int v, nt;
} e[MAX];
int n, isroot[MAX], head[MAX], cnte;
// in记录dfs过程中第一次找到该节点时的时间戳
// order记录每个时间戳对应的是哪个节点
// dep记录每个时间戳所对应的节点的深度
// 注意，时间戳的最大值是节点个数的2倍减1
int in[MAX], order[MAX << 1], dep[MAX << 1], idx;

// st表，维护dep区间最小值，最多有时间戳个数的dep
int st[MAX << 1][20], id[MAX << 1][20];

void init()
{
	cnte = 0;
	memset(head, 0, sizeof head);
	memset(isroot, -1, sizeof isroot);
}

void add(int u, int v)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

void dfs(int u, int d)
{
    in[u] = ++ idx;
    order[idx] = u;
    dep[idx] = d;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        dfs(v, d + 1);
        ++ idx;
        order[idx] = u;
        dep[idx] = d;
    }
}

void build()
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

// 返回的是区间dep最小的节点编号
int query(int l, int r)
{
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

int lca(int u, int v)
{
    return query(min(in[u], in[v]), max(in[u], in[v]));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        init();
        scanf("%d", &n);
        for (int i = 1; i < n; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            // 题目保证了u是v的父亲
            add(u, v);
            isroot[v] = 0;
        }
        idx = 0;
        for (int i = 1; i <= n; i ++) {
            if (isroot[i]) {
                dfs(i, 1);
                break;
            }
        }
        build();
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}
