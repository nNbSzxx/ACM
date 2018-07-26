#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 60;
int n, m, cnt, head[MAX], vis[MAX];
long long t, d;
struct edge{
    int v, w, nt;
} e[MAX * MAX];
vector<long long> len;

void init(void)
{
    cnt = 1;
    d = 0;
    memset(head, 0, sizeof(head));
    memset(vis, 0 ,sizeof(vis));
}
void add(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].nt = head[u];
    head[u] = cnt ++;
    return ;
}
void dfs(int x)
{
    if (x == n) {
        len.push_back(d);
        return ;
    }
    int u;
    for (int i = head[x]; i; i = e[i].nt) {
        u = e[i].v;
        if (!vis[u]) {

        }
    }
}

int main()
{
    init();
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i ++) {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1);

    return 0;
}
