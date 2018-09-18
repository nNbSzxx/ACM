#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1e6 + 10;
struct edge {
    int v, nt;
} e[MAX << 1];
int head[MAX], cnte;
int n, k, deg[MAX];
int ans;

void add(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

int dfs(int u, int fa)
{
    if (deg[u] == 1) {
        return 0;
    }
    vector<int> vec;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (v != fa)
            vec.push_back(dfs(v, u) + 1);
    }
    sort(vec.begin(), vec.end());
    while (vec.size() >= 2) {
        if (vec.back() + vec[vec.size() - 2] <= k) {
            break;
        }
        vec.pop_back();
        ++ ans;
    }
    return vec.back();
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
        ++ deg[u];
        ++ deg[v];
    }
    int root;
    for (int i = 1; i <= n; i ++) {
        if (deg[i] >= 2) {
            root = i;
            break;
        }
    }
    ans = 0;
    dfs(root, -1);
    printf("%d\n", ans + 1);

    return 0;
}
