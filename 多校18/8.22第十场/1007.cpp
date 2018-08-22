// a(n) = (n-2) * a(n-1) + (n-1) * a(n-2) - (-1)^n, if n>0.
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 1e5 + 10;
const long long mod = 998244353;

long long a[MAX];

int main()
{
    a[0] = 1;
    a[1] = 0;
    for (int i = 2; i < MAX; i ++) {
        a[i] = (i - 2) * a[i - 1] % mod + (i - 1) * a[i - 2] % mod;
        if (i & 1) {
            a[i] += 1;
        } else {
            a[i] -= 1;
            a[i] += mod;
        }
        a[i] %= mod;
    }
    int t;
    scanf("%d", &t);
    while (t --) {
        int id;
        scanf("%d", &id);
        printf("%lld\n", a[id]);
    }
    return 0;
}
