#include <bits/stdc++.h>
using namespace std;
const int MAX = 8e4 + 10;
const int MAXH = 17;
struct edge {
    int v, nt;
} e[MAX << 1];
int head[MAX], dep[MAX], val[MAX], anc[MAX][MAXH];
int cnte, n, qy;
int cnt, s[MAX];
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
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nt) {
            int v = e[i].v;
            if (v != anc[u][0]) {
                q.push(v);
                dep[v] = dep[u] + 1;
                anc[v][0] = u;
                for (int i = 1; i < MAXH; i ++) {
                    anc[v][i] = anc[anc[v][i - 1]][i - 1];
                }
            }
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
    if (dep[x] < dep[y]) swap(x, y);
    x = swim(x, dep[x] - dep[y]);
    if (x == y) return x;
    for (int i = MAXH - 1; i >= 0; i --) {
        if (anc[x][i] != anc[y][i]) {
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return anc[x][0];
}

void upscan(int u, int lc)
{
    while (u != lc) {
        s[cnt ++] = val[u];
        u = anc[u][0];
    }
}

int main()
{
    scanf("%d%d", &n, &qy);
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
    while (qy --) {
        int k, u, v;
        scanf("%d%d%d", &k, &u, &v);
        if (k == 0) {
            val[u] = v;
        } else {
            //printf("lca:  ");
            int lc = lca(u, v);
            //printf("%d\n", lc);
            cnt = 0;
            upscan(u, lc);
            upscan(v, lc);
            s[cnt ++] = val[lc];
            if (k > cnt) {
                puts("invalid request!");
            } else {
                sort(s, s + cnt);
                printf("%d\n", s[cnt - k]);
            }
        }
    }
    return 0;
}

