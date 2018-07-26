#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 5e4 +10;
const double PI = acos(-1.0);
struct point {
    int x, y, v;
    double ag;
} p[MAX * 2];
int n;

bool cmp(const point &p1, const point &p2)
{
    return p1.ag < p2.ag;
}
bool check(const point &p1, const point& p2)
{
    return (1LL * p1.x * p2.y - 1LL * p1.y * p2.x >= 0);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].v);
            p[i].ag = atan2(p[i].y, p[i].x);
            if (p[i].ag < 0) {
                p[i].ag += 2 * PI;
            }
        }
        sort(p + 1, p + 1 + n, cmp);
        for (int i = n + 1; i <= 2 * n; i ++) {
            p[i] = p[i - n];
        }
        long long sum1 = 0, sum2 = 0, tans = 0, ans = 0;
        int p1 = 1, p2 = 1;
        while (p2 <= n && check(p[p1], p[p2])) p2 ++;
        for (int i = p1; i < p2; i ++) sum1 += p[i].v;
        for (int i = p2; i < p1 + n; i ++) sum2 += p[i].v;
        for (int i = p1; i < p2; ++i) tans += 1LL * p[i].v * sum2;
        ans = max(ans, tans);
        while (p1 <= n) {
            tans = tans - p[p1].v * sum2 + p[p1].v * (sum1 - p[p1].v);
            ans = max(ans, tans);
            sum1 -= p[p1].v; sum2 += p[p1].v;
            ++ p1;
            while (p2 <= 2 * n && check(p[p1], p[p2])) {
                tans = tans - p[p2].v * sum1 + p[p2].v * (sum2 - p[p2].v);
                ans = max(ans, tans);
                sum1 += p[p2].v; sum2 -=p[p2].v;
                ++ p2;
            }
        }
        printf("%lld\n", ans);
    }
}
