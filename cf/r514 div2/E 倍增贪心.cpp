#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1e5 + 10;
const int MAXH = 19;

struct edge {
    int v, nt;
} e[MAX << 1];
int head[MAX], cnte;

int n, l;
long long s;
long long w[MAX], sum[MAX][MAXH];
int anc[MAX][MAXH];
int father[MAX], dep[MAX];
bool isson[MAX];

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

void bfs(int root)
{
    queue<int> q;
    dep[0] = 0;
    dep[root] = 1;
    w[0] = 0;
    for (int i = 0; i < MAXH; i ++) {
        anc[0][i] = 0;
        anc[root][i] = 0;
        sum[0][i] = 0;
        sum[root][i] = w[root];
    }
    q.push(root);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nt) {
            int v = e[i].v;
            if (v == father[u]) {
                continue;
            }
            dep[v] = dep[u] + 1;
            anc[v][0] = u;
            sum[v][0] = w[v];
            for (int j = 1; j < MAXH; j ++) {
                int half = anc[v][j - 1];
                anc[v][j] = anc[half][j - 1];
                sum[v][j] = sum[v][j - 1] + sum[half][j - 1];
            }
            q.push(v);
        }
    }
}

int ans = 0;
int vis[MAX];
struct node {
    int s, t;
    node(int ss, int tt) : s(ss), t(tt) {}
    bool operator<(const node& rhs) const {
        return dep[s] < dep[rhs.s];
    }
};

int cal(int u)
{
    int x = u;
    long long cursum = 0;
    int curcnt = 0;
    for (int i = MAXH - 1; i >= 0; i --) {
        if (cursum + sum[x][i] <= s && curcnt + (dep[x] - dep[anc[x][i]]) <= l) {
            cursum += sum[x][i];
            curcnt += (dep[x] - dep[anc[x][i]]);
            x = anc[x][i];
        }
    }
    return x;
}

void setvis(int st, int ds)
{
    if (vis[st]) {
        return ;
    }
    ++ ans;
    vis[st] = 1;
    for (int i = father[st]; i != ds; i = father[i]) {
        vis[i] = 1;
    }
}

void solve()
{
    priority_queue<node> q;
    for (int i = 1; i <= n; i ++) {
        if (isson[i]) {
            q.push(node(i, cal(i)));
        }
    }
    while (!q.empty()) {
        node u = q.top(); q.pop();
        setvis(u.s, u.t);
        if (u.t != 0) {
            q.push(node(u.t, cal(u.t)));
        }
    }
}

int main()
{
    scanf("%d%d%lld", &n, &l, &s);
    bool ok = 1;
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &w[i]);
        if (w[i] > s) {
            ok = 0;
        }
    }
    memset(isson, -1, sizeof isson);
    for (int i = 2; i <= n; i ++) {
        int p;
        scanf("%d", &p);
        add(p, i);
        add(i, p);
        father[i] = p;
        isson[p] = 0;
    }
    if (!ok) {
        puts("-1");
        return 0;
    }
    bfs(1);
    solve();
    printf("%d\n", ans);
    return 0;
}
