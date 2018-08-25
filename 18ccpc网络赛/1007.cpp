#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 1e4 + 10;
long long a[MAX];
long long n, s, m, k;
long long ans;
int vis[MAX];
long long sum[MAX << 1];

struct node {
    long long v;
    int id;
    node(long long vv, int idd) : v(vv), id(idd) {}
};
deque<node> q;

int main()
{
    int t, tc = 1;
    scanf("%d", &t);
    while (t --) {
        scanf("%lld%lld%lld%lld", &n, &s, &m, &k);
        for (int i = 0; i < n; i ++) {
            scanf("%lld", &a[i]);
        }
        memset(vis, 0, sizeof vis);
        int cir = n / __gcd(n, k);
        int circount = m / cir;
        int rem = m % cir;
        ans = 0;
        for (int i = 0; i < n; i ++) {
            if (!vis[i]) {
                sum[0] = 0;
                int idx = i;
                q.clear();
                q.push_back(node(0, 0));
                long long maxx = 0;
                for (int j = 1; j <= 2 * cir; j ++) {
                    sum[j] = sum[j - 1] + a[idx];
                    while (!q.empty() && q.back().v >= sum[j]) {
                        q.pop_back();
                    }
                    q.push_back(node(sum[j], j));
                    while (j - q.front().id > rem) {
                        q.pop_front();
                    }
                    maxx = max(maxx, sum[j] - q.front().v);
                    vis[idx] = 1;
                    idx = (idx + k) % n;
                }
                ans = max(ans, 1LL * sum[cir] * circount + maxx);
                //printf("%lld\n", ans);
                sum[0] = 0;
                idx = i;
                q.clear();
                q.push_back(node(0, 0));
                maxx = 0;
                for (int j = 1; j <= 2 * cir; j ++) {
                    sum[j] = sum[j - 1] + a[idx];
                    while (!q.empty() && q.back().v >= sum[j]) {
                        q.pop_back();
                    }
                    q.push_back(node(sum[j], j));
                    while (j - q.front().id > min((long long)cir, m)) {
                        q.pop_front();
                    }
                    maxx = max(maxx, sum[j] - q.front().v);
                    vis[idx] = 1;
                    idx = (idx + k) % n;
                    //if (maxx >= 20) {
                        // printf("%d %d %d %d\n", i, j, q.front().v)
                    //}
                }
                ans = max(ans, max(maxx, 1LL * sum[cir] * (circount - 1) + maxx));
            }
        }
        printf("Case #%d: %lld\n", tc ++, max(s - ans, 0LL));
    }
    return 0;
}
