#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 5e5 + 10;

long long sum[MAX];
long long dp[MAX];
int n, m;
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
    while (~scanf("%d%d", &n, &m)) {
        sum[0] = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%lld", &sum[i]);
            sum[i] += sum[i - 1];
        }
        while (!q.empty()) {
            q.pop_back();
        }
        dp[0] = 0;
        q.push_back(node(0, 0, 0));
        for (int i = 1; i <= n; i ++) {
            while (q.size() >= 2) {
                node head = q.front(); q.pop_front();
                node mid = q.front();
                if ((mid.y - head.y) < (mid.x - head.x) * 2 * sum[i]) {
                    continue;
                } else {
                    q.push_front(head);
                    break;
                }
            }

            int j = q.front().id;
            dp[i] = dp[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]) + m;

            long long inx = sum[i], iny = dp[i] + sum[i] * sum[i];
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
            q.push_back(node(inx, iny, i));
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
