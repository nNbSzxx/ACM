#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int x, int y)
{
    int r;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

main()
{
    int t;
    scanf("%lld", &t);
    while (t --) {
        int a, b, c, d, e, f;
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f);
        int aa = a - d;
        int bb = b - e;
        int cc = c - f;

        if (aa < 0) {
            aa = -aa;
            bb = -bb;
            cc = -cc;
        }

        int l, r;
        scanf("%lld%lld", &l, &r);
        int ans = 2 * aa * (r * r * r) + 3 * bb * (r * r) + 6 * cc * r;
        ans -= 2 * aa * (l * l * l) + 3 * bb * (l * l) + 6 * cc * l;
        // ans = ans;
        int dd = 6;
        int g = gcd(ans, dd);
        ans /= g;
        dd /= g;
        printf("%lld/%lld\n", ans, dd);

    }
    return 0;
}
