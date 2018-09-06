#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 2e9 + 10;
const int MAXN = 2e3 + 10;
const int MAXP = 2e3 + 10;

int n, p, w;
int ap[MAXN], bp[MAXN], as[MAXN], bs[MAXN];
int dp[MAXN][MAXP];
struct node {
    int v, id;
    node (int vv, int idd) : v(vv), id(idd) {}
};
deque<node> q;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d", &n, &p, &w);
        for (int i = 1; i <= n; i ++) {
            scanf("%d%d%d%d", &ap[i], &bp[i], &as[i], &bs[i]);
        }
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= p; j ++) {
                dp[i][j] = - INF;
            }
        }
        dp[0][0] = 0;
        int ans = 0;
        for (int i = 1; i <= w; i ++) {
            for (int j = 0; j <= p; j ++) {
                dp[i][j] = dp[i - 1][j];
                if (j <= as[i])
                    dp[i][j] = max(dp[i][j], -ap[i] * j);
                ans = max(dp[i][j], ans);
            }
        }
        // buy
        for (int i = w + 1; i <= n; i ++) {
            dp[i][0] = max(dp[i - 1][0], dp[i][0]);
            ans = max(ans, dp[i][0]);
            while (!q.empty()) {
                q.pop_back();
            }
            q.push_back(node(dp[i - w - 1][0], 0));
            for (int j = 1; j <= p; j ++) {
                while (!q.empty() && q.front().id + as[i] < j) {
                    q.pop_front();
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], q.front().v - j * ap[i]);
                ans = max(ans, dp[i][j]);
                int in = dp[i - w - 1][j] + j * ap[i];
                while (!q.empty()) {
                    if (q.back().v <= in) {
                        q.pop_back();
                    } else {
                        break;
                    }
                }
                q.push_back(node(in, j));
            }

            // sell
            dp[i][p] = max(dp[i - 1][p], dp[i][p]);
            ans = max(ans, dp[i][p]);
            while (!q.empty()) {
                q.pop_back();
            }
            q.push_back(node(dp[i - w - 1][p] + p * bp[i], p));
            for (int j = p - 1; j >= 0; j --) {
                while (!q.empty() && q.front().id - bs[i] > j) {
                    q.pop_front();
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], q.front().v - j * bp[i]);
                ans = max(ans, dp[i][j]);
                int in = dp[i - w - 1][j] + j * bp[i];
                while (!q.empty()) {
                    if (q.back().v <= in) {
                        q.pop_back();
                    } else {
                        break;
                    }
                }
                q.push_back(node(in, j));
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}
