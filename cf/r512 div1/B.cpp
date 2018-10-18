#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 3e5 + 10;

int n;
int sum[MAX], a[MAX], sum1[MAX];

int main()
{
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i ++) {
        long long t;
        scanf("%lld", &t);
        int cnt = 0;
        while (t) {
            if (t & 1) {
                cnt += 1;
            }
            t >>= 1;
        }
        a[i] = cnt;
    }
    sum[n + 1] = 0;
    for (int i = n; i >= 1; i --) {
        sum[i] = sum[i + 1] + a[i];
        sum1[i] = sum1[i + 1] + (sum[i] & 1);
    }
    for (int i = 1; i < n; i ++) {
        int r = min(n, i + 200);
        int maxx = a[i], summ = 0;
        for (int j = i + 1; j <= r; j ++) {
            if (a[j] > maxx) {
                summ += maxx;
                maxx = a[j];
            } else {
                summ += a[j];
            }
            if (summ >= maxx && ((summ + maxx) % 2 == 0)) {
                ++ ans;
            }
        }
        if (r < n) {
            if (sum[i] & 1) {
                ans += sum1[r + 2];
            } else {
                ans += (n - r) - (sum1[r + 2]);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
