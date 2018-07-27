#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;
const long long lim = LLONG_MAX;
long long n;
vector<long long> ans;
long long pow2[65];

void init()
{
    pow2[0] = 1;
    for (int i = 1; i <= 62; i ++) {
        pow2[i] = pow2[i - 1] << 1;
    }
}

int check(long long mid)
{
    //printf("mid: %lld\n", mid);
    long long t = mid;
    long long sum = 0;
    while ((mid & 1) == 0) {
        mid >>= 1;
        sum = sum + mid;
    }
    if (mid > 1) {
        if (mid >= pow2[32] + 1) {
            return 1;
        }
        long long v = (mid - 1) / 2 * mid;
        if (lim - sum <= v) {
            return 1;
        }
        sum += v;
    }
    if (sum > n) {
        return 1;
    } else if (sum == n) {
        ans.push_back(t);
        return 0;
    } else {
        return -1;
    }
}

void bins(long long left, long long step)
{
    long long l = 1, r = 1 + (n + 5 - left) / step;
    long long mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        //printf("%lld %lld %lld\n", l, r, mid);
        int state = check(left + (mid - 1) * step);
        if (state == 0) {
            return ;
        } else if (state == 1) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}

int main()
{
    init();
    scanf("%lld", &n);
    bins(3, 2);
    for (int i = 1; i <= 61; i ++) {
        if (pow2[i] - 1 > n)
            break;
        //printf("i:%d\n", i);
        bins(pow2[i], pow2[i + 1]);
    }
    if (n == pow2[62] - 1) {
        ans.push_back(pow2[62]);
    }
    if (ans.size() == 0) {
        puts("-1");
    }
    for (int i = 0; i < ans.size(); i ++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
