#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10;
int n;
struct rd {
    int t, x;
} r[MAX];

bool cmp(const rd & r1, const rd& r2)
{
    return r1.t < r2.t;
}

int main()
{
    int t, tc = 1;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d %d", &r[i].t, &r[i].x);
        }
        sort (r + 1, r + 1 + n, cmp);
        double ans = 0;
        for (int i = 2; i <= n; i ++) {
            ans = max(ans, abs(1.0 * (r[i].x - r[i - 1].x) / (r[i].t - r[i - 1].t)));
        }
        printf("Case #%d: %.2f\n", tc++, ans);
    }

}
