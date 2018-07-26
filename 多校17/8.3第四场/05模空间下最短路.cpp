#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 3e4 * 2 + 10;
long long k, dis[5][MAX];
int mod, d1, d2, d3, d4, g[5][5];
struct node{
    int v;
    long long d;
    node(int vv, long long dd) : v(vv), d(dd) {}
};

void spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    queue<node> q;
    q.push(node(2, 0));
    while (!q.empty()) {
        node now = q.front(); q.pop();
        for (int i = 1; i <= 4; i ++) {
            if (g[now.v][i] != 0x3f3f3f3f) {
                long long temp = now.d + g[now.v][i];
                if (temp < dis[i][temp % mod]) {
                    dis[i][temp % mod] = temp;
                    q.push(node(i, temp));
                }
            }
        }
    }
}

int main()
{
    //freopen("1005.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%lld%d%d%d%d", &k, &d1, &d2, &d3, &d4);
        memset(g, 0x3f, sizeof(g));
        g[1][2] = g[2][1] = d1;
        g[2][3] = g[3][2] = d2;
        g[3][4] = g[4][3] = d3;
        g[4][1] = g[1][4] = d4;
        mod = min(d1, d2) * 2;
        spfa();
        long long ans = INF;
        for (int i = 0; i < mod; i ++) {
            if (dis[2][i] >= k) {
                ans = min(ans, dis[2][i]);
            } else {
                long long del = (k - dis[2][i]) / mod * mod + dis[2][i];
                if (del < k) del += mod;
                ans = min(ans, del);
            }
        }
        printf("%lld\n", ans);
    }
}
