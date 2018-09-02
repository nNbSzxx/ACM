#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 20;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

long long dp[(1 << MAX) + 10];
int n;
int p[MAX + 5];
int a[MAX + 5], b[MAX + 5];
int shift[MAX + 5];

void init()
{
    for (int i = 0; i <= MAX; i ++) {
        shift[i] = (1 << i);
    }
}

int main()
{
    init();
    while (~scanf("%d", &n)) {
        memset(p, 0, sizeof p);

        for (int i = 0; i < n; i ++) {
            scanf("%d%d", &a[i], &b[i]);
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; j ++) {
                int t;
                scanf("%d", &t);
                p[i] |= shift[t - 1];
            }
        }
                //printf("%d\n", p[0]);

        for (int i = 0; i < (1 << n); i ++) {
            dp[i] = -INF;
        }
        dp[0] = 0;
        long long ans = 0;
        for (int mask = 0; mask < (1 << n); mask ++) {
            ans = max(ans, dp[mask]);
            //printf("%d %lld\n", mask, ans);
            for (int i = 0; i < n; i ++) {
                if (mask & shift[i]) {
                    continue;
                }
                if ((mask & p[i]) != p[i]) {
                    continue;
                }
                dp[mask | shift[i]] = max(dp[mask | shift[i]],
                                          dp[mask] + 1LL * (__builtin_popcount(mask) + 1) * a[i] + b[i]);
            }
        }
        printf("%lld\n", ans);
        //printf("%d\n", p[0]);

    }


    return 0;
}
