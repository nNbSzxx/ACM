#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const long long mod = 1e9 + 7;
long long inv2;

long long ppow(long long base, long long r)
{
    long long ret = 1;
    while (r) {
        if (r & 1) {
            ret = (ret * base) % mod;
        }
        r >>= 1;
        base = (base * base) % mod;
    }
    return ret;
}

int zerop1(long long k)
{
    int ret = 1;
    while ((k & 1) == 0) {
        k >>= 1;
        ++ ret;
    }
    return ret;
}

long long solve(long long n)
{
    if (n == 2) return 2;
    if (n == 4) return 6;
    if (n == 1) return 1;
    long long sum = 1;
    long long value = 0;
    bool find = false;
    for (int i = 62; i >= 1; i --) {
        long long bit = (1LL << i);
        //printf("%d\n", bit);
        if ((n & bit) != 0) {
            //printf("bit: %lld\n", bit);
            if (!find) {
                find = true;
                long long num = (bit - 1);
                long long nvalue = (bit >> 1);

                int numzero = zerop1(nvalue);
                //printf("%lld %lld %d\n", num, nvalue, numzero);

                sum = ((nvalue >> 1) % mod * (num - numzero) % mod + nvalue % mod * numzero + sum) % mod;
                //printf("sum: %lld\n", sum);
                value = (nvalue + 1) % mod;
            } else {
                long long num = bit;
                if (num == 2) {
                    sum = (sum + value * 2 + 1) % mod;
                    value = (value + 1) % mod;
                } else {
                    long long nvalue = (value + (num >> 1) % mod) % mod;
                    sum = (sum + (num % mod * (nvalue + value)) * inv2) % mod;
                    value = (nvalue + 1) % mod;
                }
            }
        }
    }
    if (n & 1) {
        sum = (sum + value) % mod;
    }
    return sum % mod;
}

int main()
{
    inv2 = ppow(2, mod - 2);
    int t;
    scanf("%d", &t);
    while (t --) {
        long long n;
        scanf("%lld", &n);
        long long ans = solve(n);
        printf("%lld\n", ans);
    }
    return 0;
}
