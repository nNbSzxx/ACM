#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 2e5 + 10;
const int INF = 2e8 + 10;

struct node {
    int v, id;
    node(int vv, int idd) : v(vv), id(idd) {}
};

int n, l, r;
int v[MAX];
deque<node> q;
int dp[MAX];



int main()
{
    while (~scanf("%d%d%d", &n, &l, &r)) {
        for (int i = 0; i <= n; i ++) {
            scanf("%d", &v[i]);
        }
        for (int i = 1; i <= n; i ++) {
            dp[i] = -INF;
        }
        dp[0] = 0;
        q.push_back(node(0, 0));

        for (int i = l; i <= n; i ++) {
            while (!q.empty() && q.front().id < i - r) {
                q.pop_front();
            }
            if (q.front().v != -INF) {
                dp[i] = q.front().v + v[i];
            }
            while (!q.empty()) {
                if (q.back().v <= dp[i - l + 1]) {
                    q.pop_back();
                } else {
                    break;
                }
            }
            q.push_back(node(dp[i - l + 1], i - l + 1));
        }
        int ans = -INF;
        for (int i = max(n - r + 1, 0); i <= n; i ++) {
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
