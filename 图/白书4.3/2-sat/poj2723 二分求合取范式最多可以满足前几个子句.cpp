#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXN = 3010;
const int MAXM = 5010;

struct edge {
    int v, nt;
} e[MAXM];
int head[MAXN], cnte;
int dfn[MAXN], low[MAXN], idx, color[MAXN], cntc;
stack<int> s;

int n, m;
int u[MAXM], v[MAXM];
int keytogp[MAXN];

inline int nott(int x)
{
    return (x >= n) ? x - n : x + n;
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
        } else if (!color[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++ cntc;
        while (true) {
            int now = s.top();
            s.pop();
            color[now] = cntc;
            if (now == u) {
                break;
            }
        }
    }
}

bool check(int mid)
{
    memset(head, 0, sizeof head);
    cnte = 0;
    //printf("mid: %d\n", mid);
    for (int i = 1; i <= mid; i ++) {
        add(nott(u[i]), v[i]);
        //printf("%d %d\n", nott(u[i]), v[i]);
        add(nott(v[i]), u[i]);
        //printf("%d %d\n", nott(v[i]), u[i]);
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
    int l = 1, r = m, ret = 0, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ret = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ret;
}

int main()
{
    while (~scanf("%d%d", &n, &m), n || m) {
        for (int i = 0; i < n; i ++) {
            int x, y;
            scanf("%d%d", &x, &y);
            keytogp[x] = i;
            keytogp[y] = i + n;
        }
        for (int i = 1; i <= m; i ++) {
            int x, y;
            scanf("%d%d", &x, &y);
            int a = keytogp[x];
            int b = keytogp[y];
            u[i] = a;
            v[i] = b;
        }
        printf("%d\n", bins());
    }
    return 0;
}





