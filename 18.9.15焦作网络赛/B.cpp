#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e3 + 5;
const long long INF = 1e18 + 10;
long long ddp[MAX][8], xdp[MAX][8];
int n, m, k;
int a[MAX];
char s[15];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
        }
        scanf(" %s", s);
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                ddp[i][j] = -INF;
                xdp[i][j] = INF;
            }
        }
        for (int i = 0; i <= n; i ++) {
            xdp[i][0] = ddp[i][0] = k;
        }


        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                switch (s[j - 1]) {
                case '+':
                    ddp[i][j] = -INF;
                    xdp[i][j] = INF;
                    if (ddp[i - 1][j - 1] != -INF) {
                        ddp[i][j] = max(ddp[i][j], ddp[i - 1][j - 1] + a[i]);
                        xdp[i][j] = min(xdp[i][j], ddp[i - 1][j - 1] + a[i]);
                    }
                    if (xdp[i - 1][j - 1] != INF) {
                        ddp[i][j] = max(ddp[i][j], xdp[i - 1][j - 1] + a[i]);
                        xdp[i][j] = min(xdp[i][j], xdp[i - 1][j - 1] + a[i]);
                    }
                    ddp[i][j] = max(ddp[i - 1][j], ddp[i][j]);
                    xdp[i][j] = min(xdp[i - 1][j], xdp[i][j]);
                    break;
                case '-':
                    ddp[i][j] = -INF;
                    xdp[i][j] = INF;
                    if (ddp[i - 1][j - 1] != -INF) {
                        ddp[i][j] = max(ddp[i][j], ddp[i - 1][j - 1] - a[i]);
                        xdp[i][j] = min(xdp[i][j], ddp[i - 1][j - 1] - a[i]);
                    }
                    if (xdp[i - 1][j - 1] != INF) {
                        ddp[i][j] = max(ddp[i][j], xdp[i - 1][j - 1] - a[i]);
                        xdp[i][j] = min(xdp[i][j], xdp[i - 1][j - 1] - a[i]);
                    }
                    ddp[i][j] = max(ddp[i - 1][j], ddp[i][j]);
                    xdp[i][j] = min(xdp[i - 1][j], xdp[i][j]);
                    break;
                case '*':
                    ddp[i][j] = -INF;
                    xdp[i][j] = INF;
                    if (ddp[i - 1][j - 1] != -INF) {
                        ddp[i][j] = max(ddp[i][j], ddp[i - 1][j - 1] * a[i]);
                        xdp[i][j] = min(xdp[i][j], ddp[i - 1][j - 1] * a[i]);
                    }
                    if (xdp[i - 1][j - 1] != INF) {
                        ddp[i][j] = max(ddp[i][j], xdp[i - 1][j - 1] * a[i]);
                        xdp[i][j] = min(xdp[i][j], xdp[i - 1][j - 1] * a[i]);
                    }
                    ddp[i][j] = max(ddp[i - 1][j], ddp[i][j]);
                    xdp[i][j] = min(xdp[i - 1][j], xdp[i][j]);
                    break;
                case '/':
                    ddp[i][j] = -INF;
                    xdp[i][j] = INF;
                    if (ddp[i - 1][j - 1] != -INF) {
                        ddp[i][j] = max(ddp[i][j], ddp[i - 1][j - 1] / a[i]);
                        xdp[i][j] = min(xdp[i][j], ddp[i - 1][j - 1] / a[i]);
                    }
                    if (xdp[i - 1][j - 1] != INF) {
                        ddp[i][j] = max(ddp[i][j], xdp[i - 1][j - 1] / a[i]);
                        xdp[i][j] = min(xdp[i][j], xdp[i - 1][j - 1] / a[i]);
                    }
                    ddp[i][j] = max(ddp[i - 1][j], ddp[i][j]);
                    xdp[i][j] = min(xdp[i - 1][j], xdp[i][j]);
                    break;
                }
            }
        }
        printf("%lld\n", ddp[n][m]);
    }
    return 0;
}
