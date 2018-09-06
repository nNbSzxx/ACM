#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;
const int MAXW = 105;
const int MAXN = 16005;
const int INF = 2e8 + 5;

int n, w;
struct worker {
    int l, p, s;
} wo[MAXW];
int dp[MAXW][MAXN];
struct node {
    int v, id;
    node(int vv, int idd): v(vv), id(idd) {}
};
deque<node> q;

bool cmp(const worker& w1, const worker& w2)
{
    return w1.s < w2.s ;
}

int main()
{
    while (~scanf("%d%d", &n, &w)) {
        for (int i = 1; i <= w; i ++) {
            scanf("%d%d%d", &wo[i].l, &wo[i].p, &wo[i].s);
        }
        for (int i = 0; i <= w; i ++) {
            for (int j = 0; j <= n; j ++) {
                dp[i][j] = -INF;
            }
        }
        dp[0][0] = 0;
        sort(wo + 1, wo + 1 + w, cmp);
        for (int i = 1; i <= w; i ++) {
            while (!q.empty()) {
                q.pop_back();
            }
            for (int j = max(0, wo[i].s - wo[i].l); j < wo[i].s; j ++) {
                int in = dp[i - 1][j] - j * wo[i].p;
                while (!q.empty() && q.back().v <= in) {
                    q.pop_back();
                }
                q.push_back(node(in, j));
            }
            for (int j = wo[i].s; j <= min(wo[i].s + wo[i].l - 1, n); j ++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                while (!q.empty() && q.front().id + wo[i].l < j) {
                    q.pop_front();
                }
                dp[i][j] = max(dp[i][j], q.front().v + j * wo[i].p);
                int in = dp[i - 1][j] - j * wo[i].p;
                while (!q.empty() && q.back().v <= in) {
                    q.pop_back();
                }
                q.push_back(node(in, j));
            }
        }
        int ans = -INF;
        for (int i = 1; i <= w; i ++) {
            ans = max(ans, dp[i][n]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
