#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e18 + 10;

long long p(long long base, long long r)
{
    long long ret = 1;
    while (r) {
        if (r & 1) {
            ret *= base;
        }
        r >>= 1;
        base *= base;
    }
    return ret;
}

int main()
{
    //cout << (p(15, 15) >= 1e18) << endl;
    long long n;
    while (~scanf("%lld", &n)) {
        long long r = 15;
        long long l = 1;
        long long mid, ans = 16;
        for (int i = 1; i <= 15; i ++) {
            if (p(i, i) <= n) {
                ans = i;
            }
        }
        printf("%lld\n", ans);
    }

}
