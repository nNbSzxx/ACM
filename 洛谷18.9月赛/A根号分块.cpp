#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<long long, int> mp;
long long m, k;

long long mul(long long a, long long b)
{
    return (__int128)a * b % m;
}

long long qkp(long long base, long long r)
{
    long long ret = 1;
    while (r) {
        if (r & 1) {
            ret = mul(ret, base);
        }
        base = mul(base, base);
        r >>= 1;
    }
    return ret;
}

int main()
{
    scanf("%lld%lld", &k, &m);
    k = (k * 9 + 1) % m;
    long long b = sqrt(m) + 1;
    long long sum = 1;
    for (int i = 0; i < b; i ++) {
        if (!mp.count(sum)) {
            mp.insert(make_pair(sum, i));
        }
        sum = (sum * 10) % m;
    }
    for (int i = 0; i <= b; i ++) {
        long long cdiv = mul(k, qkp(qkp(sum, i), m - 2));
        auto it = mp.find(cdiv);
        if (it != mp.end()) {
            printf("%lld\n", it->second + i * b);
            break;
        }
    }
    return 0;
}
