#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        long long n, m, x;
        scanf("%lld%lld%lld", &n, &m, &x);
        long long livemax = min(n, m);
        long long convert = livemax;
        long long ans = livemax * max(0LL, n - convert) * x;

        long long c = n / 2;
        long long t = c * max(0LL, n - c) * x;
        if (c <= m) {
            if (t > ans || (t == ans && c < convert)) {
                ans = t;
                convert = c;
            }
        }
        if (n & 1) {
            c += 1;
            t = c * max(0LL, n - c) * x;
            if (c <= m) {
                if (t > ans || (t == ans && c < convert)) {
                    ans = t;
                    convert = c;
                }
            }
        }

        printf("%lld %lld\n", convert, ans);
    }

    return 0;
}
