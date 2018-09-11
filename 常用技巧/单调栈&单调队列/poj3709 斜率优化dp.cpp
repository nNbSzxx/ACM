#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 5e5 + 10;
long long INF = 5e5 * 5e5 + 10;
long long dp[MAX], sum[MAX];
long long a[MAX];
int n, k;
struct node {
    long long x, y;
    int id;
    node (long long xx, long long yy, int idd) : x(xx), y(yy), id(idd) {}
};
deque<node> q;

long long det(long long x1, long long y1, long long x2, long long y2)
{
    return x1 * y2 - x2 * y1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &k);
        sum[0] = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%lld", &a[i]);
            sum[i] = (sum[i - 1] + a[i]);
        }
        dp[0] = 0;
        while (!q.empty()) {
            q.pop_back();
        }
        for (int i = 1; i < k; i ++) {
            dp[i] = INF;
        }
        q.push_back(node(a[1], 0, 0));

        for (int i = k; i <= n; i ++) {
            while (q.size() >= 2) {
                node head = q.front(); q.pop_front();
                node mid = q.front();
                if ((mid.y - head.y) < i * (mid.x - head.x)) {
                    continue;
                } else {
                    q.push_front(head);
                    break;
                }
            }

            int j = q.front().id;
            dp[i] = dp[j] + sum[i] - sum[j] - a[j + 1] * (i - j);

            int id = i - k + 1;
            if (dp[id] == INF) {
                continue;
            }
            long long inx = a[id + 1], iny = dp[id] - sum[id] + 1LL * id * a[id + 1];
            while (q.size() >= 2) {
                node mid = q.back(); q.pop_back();
                node head = q.back();
                if (det(inx - mid.x, iny - mid.y, head.x - mid.x, head.y - mid.y) <= 0) {
                    continue;
                } else {
                    q.push_back(mid);
                    break;
                }
            }
            q.push_back(node(inx, iny, id));
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
