#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
const int MAXN = 505 * 2;
const int MAXM = 1003 * 2 + 1003 * 4 + 503 * 8;

struct edge {
    int v, nt;
} e[MAXM];
int head[MAXN], cnte;
int dfn[MAXN], low[MAXN], idx, color[MAXN], cntc;
stack<int> s;

int n, mh, ml;
int sx1, sy1, sx2, sy2, pass;
int dis1[MAXN], dis2[MAXN];
int h1[MAXN], h2[MAXN];
int l1[MAXN], l2[MAXN];

inline int dis(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ idx;
    s.push(u);
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!color[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++ cntc;
        while (true) {
            int now = s.top();
            s.pop();
            color[now] = cntc;
            if (u == now) {
                break;
            }
        }
    }
}

bool check(int mid)
{
    memset(head, 0, sizeof head);
    cnte = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            int flag = 0;
            int diss = dis1[i] + dis1[j];
            if (diss > mid) {
                add(i, j + n);
                add(j, i + n);
                ++ flag;
            }
            diss = dis2[i] + dis2[j];
            if (diss > mid) {
                add(i + n, j);
                add(j + n, i);
                ++ flag;
            }
            diss = dis1[i] + dis2[j] + pass;
            if (diss > mid) {
                add(i, j);
                add(j + n, i + n);
                ++ flag;
            }
            diss = dis2[i] + dis1[j] + pass;
            if (diss > mid) {
                add(i + n, j + n);
                add(j, i);
                ++ flag;
            }
            if (flag == 4) {
                return false;
            }
        }
    }

    for (int i = 1; i <= mh; i ++) {
        int a = h1[i], b = h2[i];
        add(a, b + n);
        add(b, a + n);
    }
    for (int i = 1; i <= ml; i ++) {
        int a = l1[i], b = l2[i];
        add(a, b);
        add(a + n, b + n);
        add(b, a);
        add(b + n, a + n);
    }
    memset(dfn, 0, sizeof dfn);
    idx = 0;
    memset(color, 0, sizeof color);
    cntc = 0;
    for (int i = 0; i < 2 * n; i ++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 0; i < n; i ++) {
        if (color[i] == color[i + n]) {
            return false;
        }
    }
    return true;
}

int bins()
{
    int l = 0, r = 4e6 + 3, mid, ret = -1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ret = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ret;
}

int main()
{
    while (~scanf("%d%d%d", &n, &mh, &ml)) {
        scanf("%d%d%d%d", &sx1, &sy1, &sx2, &sy2);
        pass = dis(sx1, sy1, sx2, sy2);
        for (int i = 0; i < n; i ++) {
            int x, y;
            scanf("%d%d", &x, &y);
            dis1[i] = dis(x, y, sx1, sy1);
            dis2[i] = dis(x, y, sx2, sy2);
        }

        for (int i = 1; i <= mh; i ++) {
            scanf("%d%d", &h1[i], &h2[i]);
            h1[i] --;
            h2[i] --;
        }
        for (int i = 1; i <= ml; i ++) {
            scanf("%d%d", &l1[i], &l2[i]);
            l1[i] --;
            l2[i] --;
        }
        printf("%d\n", bins());
    }
    return 0;
}




