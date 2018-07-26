#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const long long mod = 1e9 + 7;

long long p(long long base, long long r)
{
    long long ret = 1;
    base %= mod;
    while (r) {
        if (r & 1) {
            ret = ret * base % mod;
        }
        base = base * base % mod;
        r >>= 1;
    }
    return ret % mod;
}

int main()
{
    long long n, k;
    int t = 1;
    while (~scanf("%lld%lld", &n, &k)) {
        printf("Case #%d: %lld\n", t ++, p(n, k));
    }
    return 0;
}
