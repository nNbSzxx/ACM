#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        long long n;
        scanf("%lld", &n);
        int flag = 0;
        long long l = 1, r = 1e6 + 1;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            long long temp = 3 * mid * mid + 3 * mid + 1;
            if (temp == n) {
                flag = 1;
                break;
            } else if (temp > n) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (flag) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}
