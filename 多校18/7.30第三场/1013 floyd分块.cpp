#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 55;
const int INF = 0x3f3f3f3f;
int dis[210][MAX][MAX]; // dis[i, u, v] 恰好走i条边从u到v的最短距离
int disleast[210][MAX][MAX]; // disleast[i, u, v] 至少走i条边从u到v的最短距离
int dis100[110][MAX][MAX]; // dis100[i, u, v] 恰好走100i条边从u到v的最短距离
int n, m, q;

void pre()
{
    for (int step = 2; step <= 200; step ++) {
        for (int k = 1; k <= n; k ++) {
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= n; j ++) {
                    dis[step][i][j] = min(dis[step][i][j], dis[step - 1][i][k] + dis[1][k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            disleast[200][i][j] = dis[200][i][j];
        }
    }

    for (int step = 199; step >= 1; step --) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                disleast[step][i][j] = min(dis[step][i][j], disleast[step + 1][i][j]);
            }
        }
    }

    memset(dis100, 0x3f, sizeof dis100);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            dis100[1][i][j] = dis[100][i][j];
        }
    }
    for (int step = 2; step <= 100; step ++) {
        for (int k = 1; k <= n; k ++) {
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= n; j ++) {
                    dis100[step][i][j] = min(dis100[step][i][j], dis100[step - 1][i][k] + dis100[1][k][j]);
                }
            }
        }
    }
}

int query(int u, int v, int k)
{
    if (k <= 100) {
        if (disleast[k][u][v] == INF) {
            return -1;
        } else {
            return disleast[k][u][v];
        }
    }
    int ans = INF;
    k -= 1;
    int hund = k / 100;
    int lea = k % 100 + 1;
    for (int i = 1; i <= n; i ++) {
        ans = min(ans, dis100[hund][u][i] + disleast[lea][i][v]);
    }
    if (ans == INF) {
        return -1;
    } else {
        return ans;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        memset(dis, 0x3f, sizeof dis);
        scanf("%d%d", &n, &m);

        int u, v, w;
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            dis[1][u][v] = min(dis[1][u][v], w);
        }
        pre();
        int k;
        scanf("%d", &q);
        while (q --) {
            scanf("%d%d%d", &u, &v, &k);
            printf("%d\n", query(u, v, k));
        }
    }
    return 0;
}
