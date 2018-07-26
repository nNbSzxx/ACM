#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int mod = 998244353;
const int MAX = 3e5 + 10;
struct node {
    int v;
    long long w;
    node(int vv, int ww) : v (vv), w (ww) {}
};
vector<node> e[MAX * 2];
int n, vis[MAX * 2], degree[MAX * 2];
long long ans;

void tsort(void)
{
    queue<int> q;
    int u;
    for (int i = n + 1; i <= 2 * n; i ++) {
        if (degree[i] == 1) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty()) {
        int v;
        long long w = -1;
        u = q.front(); q.pop();
        for (int i = 0; i < e[u].size(); i ++) {
            if (!vis[e[u][i].v]) {
                v = e[u][i].v;
                w = e[u][i].w;
                break;
            }
        }
        if (w == -1) {
            continue;
        }
        // problem here
        vis[v] = 1;
        ans = ans * w % mod;
        for (int i = 0; i < e[v].size(); i ++) {
            int vv = e[v][i].v;
            -- degree[vv];
            if (!vis[vv] && degree[vv] == 1) {
                vis[vv] = 1;
                q.push(vv);
            }
        }

    }
    return ;
}

void dfs(int x, int use, int bg, int fa, long long &a1, long long &a2)
{
    for (int i = 0; i < e[x].size(); i ++) {
        int v = e[x][i].v;
        if (!vis[v]) {
            vis[v] = 1;
            if (use) {
                a1 = a1 * e[x][i].w % mod;
            } else {
                a2 = a2 * e[x][i].w % mod;
            }
            dfs(v, ~use, bg, x, a1, a2);
            return ;
        } else if (v == bg && fa != bg) {
            if (use) {
                a1 = a1 * e[x][i].w % mod;
            } else {
                a2 = a2 * e[x][i].w % mod;
            }
            return ;
        }
    }
}

int main()
{
    //freopen("1007.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t --) {
        int v1, v2;
        long long w1, w2;
        memset(degree, 0, sizeof degree);
        memset(vis, 0, sizeof vis);
        ans = 1;
        scanf("%d", &n);
        for(int i = 1; i <= n * 2; i ++) {
            e[i].clear();
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%d%lld%d%lld", &v1, &w1, &v2, &w2);
            degree[i] += 2;
            degree[v1 + n] += 1;
            degree[v2 + n] += 1;
            e[i].push_back(node(v1 + n, w1));
            e[v1 + n].push_back(node(i, w1));
            e[i].push_back(node(v2 + n, w2));
            e[v2 + n].push_back(node(i, w2));
        }

        tsort();
        //cout << "aaaaaaaaaaa" << endl;
        /*
        for (int i = 1; i <= 2 * n; i ++) {
            cout << vis[i] << " ";
        }
        cout << endl;
        */
        cout << ans << " " << ans <<endl;

        for (int i = 1; i <= n; i ++) {
            if (!vis[i]) {
                long long a1 = 1, a2 = 1;
                vis[i] = 1;
                dfs(i, 0, i, -1, a1, a2);
                ans = ans * (a1 + a2) % mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
9999
4
1 1 3 3
1 4 2 5
1 7 2 6
3 1 4 2 */
