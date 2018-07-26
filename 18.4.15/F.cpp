#include <iostream>
#include <cstdio>
using namespace std;
const long long MAX = 1e12;
long long a[300010], mul[300010];
long long ddiv[300010], cnt = 1, times[300010];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
    }
    mul[0] = 1;
    for (int i = 1; i <= n; i ++) {
        if (a[i] > MAX / mul[i - 1]) break;
        mul[i] = mul[i - 1] * a[i];
        if (a[i] != 1 || i == 1) {
            ddiv[cnt ++] = mul[i];
        }
        times[cnt - 1] += 1;
    }
    long long x;
    long long sum = 0;
    for (int i = 1; i < cnt; i ++) {
        sum += times[i];
    }
    while (m --) {
        scanf("%lld", &x);
        long long ans = 0;
        for (int i = 1; i < cnt; i ++) {
            ans += ((x - 1) / ddiv[i] + 1) * times[i];
        }
        ans = ans + n - sum;
        printf("%lld\n", ans);
    }
    return 0;
}
