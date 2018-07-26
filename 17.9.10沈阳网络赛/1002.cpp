#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long m, k;
    while (~scanf("%lld%lld", &m, &k)) {
        long long ans = 1LL * (m - k + 1) * k;
        printf("%lld\n", ans);
    }
}
