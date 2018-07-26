#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e6 + 10;
struct edge {
    int v, w, nt;
} e[2 * MAX];
long long ans;
int n, k, head[MAX], cnt, degree[MAX];

void init(void)
{
    ans = 0;
    memset(head, 0, sizeof(int) * (n + 3));
}

void add(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].nt = head[u];
    head[u] = cnt ++;
    return ;
}
void dfs(int x, int fa)
{
    degree[x] = 1;
    for (int i = head[x]; i; i = e[i].nt) {
        if (e[i].v != fa) {
            dfs(e[i].v, x);
            degree[x] += degree[e[i].v];
            ans += 1LL * min(degree[e[i].v], k) * e[i].w;
        }
    }
}

int main()
{
    while (~scanf("%d%d", &n, &k)) {
        int u, v, w;
        cnt = 1;
        for (int i = 1; i < n; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        dfs(1, -1);
        printf("%lld\n", ans);
        init();
    }
    return 0;
}
