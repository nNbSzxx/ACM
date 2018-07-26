#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
const int MAX = 210;
const int INF = 0x3f3f3f3f;

int k, n, m, a[MAX], b[MAX], g[MAX][MAX];
int layer[MAX];

bool countLayer(void)
{
    queue<int> q;
    int vis[MAX];
    memset(vis, 0, sizeof(vis));
    layer[0] = 0;
    vis[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 0; i <= 2 * n + 1; i ++) {
            if (g[now][i] > 0 && !vis[i]) {
                vis[i] = 1;
                layer[i] = layer[now] + 1;
                q.push(i);
                if (i == 2 * n  + 1) {
                    return true;
                }
            }

        }
    }
    return false;
}
int dinic(void)
{
    int vis[MAX];
    deque<int> q;
    int maxflow = 0;
    while (countLayer()) {
        memset(vis, 0 ,sizeof(vis));
        q.clear();
        q.push_back(0);
        vis[0] = 1;
        while (!q.empty()) {
            int now = q.back();
            if (now == 2 * n + 1) {
                int minn = INF;
                int minid;
                for (int i = 1; i < q.size(); i ++) {
                    int u = q[i - 1];
                    int v = q[i];
                    if (g[u][v] > 0 && g[u][v] < minn) {
                        minid = u;
                        minn = g[u][v];
                    }
                }
                maxflow += minn;
                for (int i = 1; i < q.size(); i ++) {
                    int u = q[i - 1];
                    int v = q[i];
                    g[u][v] -= minn;
                    g[v][u] += minn;
                }
                while (q.back() != minid && !q.empty())
                    vis[q.back()] = 0, q.pop_back();
            } else {
                int i;
                for (i = 0; i <= 2 * n + 1; i ++) {
                    if (!vis[i] && g[now][i] > 0 && layer[now] + 1 == layer[i]) {
                        q.push_back(i);
                        vis[i] = 1;
                        break;
                    }
                }
                if (i > 2 * n + 1) {
                    q.pop_back();
                }
            }

        }
    }
    return maxflow;
}

int main()
{
    int suma = 0, sumb = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        sumb += b[i];
    }
    memset(g, 0 , sizeof(g));
    int u, v;
    for (int i = 1; i <= n; i ++) {
        g[i][n + i] = INF;
    }
    for (int i = 1; i <= n; i ++) {
        g[0][i] = a[i];
        g[i + n][2 * n + 1] = b[i];
    }
    for (int i = 1; i <= m; i ++) {
        cin >> u >> v;
        g[u][v + n] = g[v][u + n] = INF;
    }
    int maxflow = dinic();

    if (maxflow == suma && maxflow == sumb) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (j >= 2) {
                    cout << " ";
                }
                if (g[i][j +n] > 200) cout << INF - g[i][j + n];
                    else cout << g[i][j + n];
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
