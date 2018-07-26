#include <bits/stdc++.h>
using namespace std;
int x, y, x1, x2, y1, y2, n, m;
long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long g = exgcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - (a / b) * y;
    return g;
}

int main()
{
    int t, tc = 1;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
        n *= 2;
        m *= 2;
        x1 *= 2;
        y1 *= 2;
        x2 *= 2;
        y2 *= 2;
        int tx = n - (x1 + x2) / 2, ty = m - (y1 + y2) / 2;
        long long time = -1;
        if (x1 == x2 && y1 == y2) time = 0;
        if (x1 == x2 && y1 != y2) time = ty;
        if (x1 != x2 && y1 == y2) time = tx;
        if (x1 != x2 && y1 != y2) {
            long long x, y;
            long long g = exgcd(n, m, x, y);
            if ((ty - tx) % g == 0) {
                x = (ty - tx) / g * x;
                x = (x % (m / g) + m / g) % (m / g);
                time = tx + n * x;
            }

        }
        printf("Case #%d:\n", tc ++);
        if (time == -1) {
            puts("Collision will not happen.");
        } else {
            x1 = (x1 + time) % (2 * n);
            y1 = (y1 + time) % (2 * m);
            if (x1 > n) x1 = 2 * n - x1;
            if (y1 > m) y1 = 2 * m - y1;
            printf("%.1f %.1f\n", x1 / 2.0, y1 / 2.0);
        }
    }
}
