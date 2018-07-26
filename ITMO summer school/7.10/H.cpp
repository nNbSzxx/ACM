#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 10;
int flag[MAX * 3], head[MAX * 3];
struct edge {
    int v, nt;
} e[MAX * 2];
void add(int u, int v)
{
    e[cnt].v = v;
    e[cnt].nt = head[u];
    head[u] = cnt;
    ++ cnt;
    return ;
}
int main()
{
    memset(flag, 0, sizeof(flag));
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i ++) {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    if (n % 3) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    return 0;
}

