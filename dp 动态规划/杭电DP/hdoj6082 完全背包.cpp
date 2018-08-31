#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 10;
const int MAXM = 1e3 + 10;
long long dp[MAXM][15];
int a[MAXN], b[MAXN], kk[MAXM], p[MAXM];
int n, m;

int main()
{
    while(~scanf("%d%d", &n, &m)) {
        for (int i =1; i <= n; i++) {
            scanf("%d%d", &a[i], &b[i]);
        }
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d", &kk[i], &p[i]);
        }
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i <= 10; i ++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= 1000; j ++) {
                for (int k = 0; k < min(p[i], 11); k ++) {
                    int att = p[i] - k;
                    if (att < j) {
                        dp[j][k] = min(dp[j][k], dp[j - att][k] + kk[i]);
                    } else {
                        dp[j][k] = min(dp[j][k], dp[0][k] + kk[i]);
                    }
                }
            }
        }

        for (int i = 999; i; i --) {
            for (int j = 0; j <= 10; j ++) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            }
        }
        long long ans = 0;
        int flag = 1;
        for (int i = 1; i <= n; i ++) {
            if (dp[a[i]][b[i]] != INF) {
                ans += dp[a[i]][b[i]];
            } else {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%I64d\n", ans);
        } else {
            puts("-1");
        }
    }
    return 0;
}
