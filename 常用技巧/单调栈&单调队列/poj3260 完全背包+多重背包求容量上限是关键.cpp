#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100;
const int MAXM = 10000;
const int MAXV = 120;
const int INF = 0x3f3f3f3f;
int n, m;
int c[MAXN + 10], v[MAXN + 10];
int cnt, cost[MAXN * 10 + 10], val[MAXN * 10 + 10];
int dp[MAXM + MAXV * MAXV + 10];
int dpsaler[MAXV * MAXV + 10];

void split(int x)
{
    int curc = 1;
    while (curc <= c[x]) {
        ++ cnt;
        cost[cnt] = v[x] * curc;
        val[cnt] = curc;
        c[x] -= curc;
        curc <<= 1;
    }
    if (c[x]) {
        ++ cnt;
        cost[cnt] = v[x] * c[x];
        val[cnt] = c[x];
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &v[i]);
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &c[i]);
        }
        cnt = 0;
        for (int i = 1; i <= n; i ++) {
            split(i);
        }
        memset(dp, 0x3f, sizeof dp);
        //printf("%d\n", cost[29]);
        dp[0] = 0;
        for (int i = 1; i <= cnt; i ++) {
            for (int j = m + MAXV * MAXV; j >= cost[i]; j --) {
                dp[j] = min(dp[j - cost[i]] + val[i], dp[j]);
            }
        }

        memset(dpsaler, 0x3f, sizeof dpsaler);
        dpsaler[0] = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = v[i]; j <= MAXV * MAXV; j ++) {
                dpsaler[j] = min(dpsaler[j], dpsaler[j - v[i]] + 1);
            }
        }
        int ans = INF;
        for (int i = 0; i <= MAXV * MAXV; i ++) {
            int t = dp[m + i] + dpsaler[i];
            ans = min(ans, t);
        }
        if (ans == INF) {
            puts("-1");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
