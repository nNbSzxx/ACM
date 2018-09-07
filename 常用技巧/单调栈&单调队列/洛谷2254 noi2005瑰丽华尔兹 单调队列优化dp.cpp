#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 205;
const int MAXM = 205;
const int MAXS = 205;
const int INF = 0x3f3f3f3f;

int n, m, s;
int l[MAXS], r[MAXS], dir[MAXS];
int dp[MAXS][MAXN][MAXM];
int x, y;
char mp[MAXN][MAXM];
struct node {
    int v, id;
    node (int vv, int idd): v(vv), id(idd) {}
};
deque<node> q;

int main()
{
    scanf("%d%d%d%d%d", &n, &m, &x, &y, &s);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            scanf(" %c", &mp[i][j]);
        }
    }
    for (int i = 1; i <= s; i ++) {
        scanf("%d%d%d", &l[i], &r[i], &dir[i]);
    }
    for (int k = 0; k <= s; k ++) {
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                dp[k][i][j] = -INF;
            }
        }
    }
    dp[0][x][y] = 0;
    for (int k = 1; k <= s; k ++) {
        int dis = r[k] - l[k] + 1;
        if (dir[k] <= 2) {
            // up && down
            for (int j = 1; j <= m; j ++) {
                while (!q.empty()) {
                    q.pop_back();
                }
                if (dir[k] == 2) {
                    // down
                    q.push_back(node(-INF, 0));
                    for (int i = 1; i <= n; i ++) {
                        if (mp[i][j] == 'x') {
                            dp[k][i][j] = -INF;
                            while (!q.empty()) {
                                q.pop_back();
                            }
                            q.push_back(node(-INF, i));
                            continue;
                        }
                        while (!q.empty() && q.front().id + dis < i) {
                            q.pop_front();
                        }
                        dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j]);
                        dp[k][i][j] = max(dp[k][i][j], q.front().v + i);
                        int in = dp[k - 1][i][j] - i;
                        while (!q.empty() && q.back().v <= in) {
                            q.pop_back();
                        }
                        q.push_back(node(in, i));
                    }
                } else {
                    // up
                    q.push_back(node(-INF, n + 1));
                    for (int i = n; i >= 1; i --) {
                        if (mp[i][j] == 'x') {
                            dp[k][i][j] = -INF;
                            while (!q.empty()) {
                                q.pop_back();
                            }
                            q.push_back(node(-INF, i));
                            continue;
                        }
                        while (!q.empty() && q.front().id - dis > i) {
                            q.pop_front();
                        }
                        dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j]);
                        dp[k][i][j] = max(dp[k][i][j], q.front().v - i);
                        int in = dp[k - 1][i][j] + i;
                        while (!q.empty() && q.back().v <= in) {
                            q.pop_back();
                        }
                        q.push_back(node(in, i));
                    }
                }
            }
        } else {
            // left && right
            for (int i = 1; i <= n; i ++) {
                while (!q.empty()) {
                    q.pop_back();
                }
                if (dir[k] == 4) {
                    // right
                    q.push_back(node(-INF, 0));
                    for (int j = 1; j <= m; j ++) {
                        if (mp[i][j] == 'x') {
                            dp[k][i][j] = -INF;
                            while (!q.empty()) {
                                q.pop_back();
                            }
                            q.push_back(node(-INF, j));
                            continue;
                        }
                        while (!q.empty() && q.front().id + dis < j) {
                            q.pop_front();
                        }
                        dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j]);
                        dp[k][i][j] = max(dp[k][i][j], q.front().v + j);
                        int in = dp[k - 1][i][j] - j;
                        while (!q.empty() && q.back().v <= in) {
                            q.pop_back();
                        }
                        q.push_back(node(in, j));
                    }
                } else {
                    // left
                    q.push_back(node(-INF, m + 1));
                    for (int j = m; j >= 1; j --) {
                        if (mp[i][j] == 'x') {
                            dp[k][i][j] = -INF;
                            while (!q.empty()) {
                                q.pop_back();
                            }
                            q.push_back(node(-INF, j));
                            continue;
                        }
                        while (!q.empty() && q.front().id - dis > j) {
                            q.pop_front();
                        }
                        dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j]);
                        dp[k][i][j] = max(dp[k][i][j], q.front().v - j);
                        int in = dp[k - 1][i][j] + j;
                        while (!q.empty() && q.back().v <= in) {
                            q.pop_back();
                        }
                        q.push_back(node(in, j));
                    }
                }
            }
        }
    }
    int ans = -INF;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            ans = max(ans, dp[s][i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
