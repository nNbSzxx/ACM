#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 40;
int n;
long long a[MAX];
pair<long long, int> sum[1 << 20];
pair<long long, int> norep[1 << 20];
int ncnt;

inline long long aabs(long long x)
{
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

long long bins(long long x)
{
    int l = 0, r = ncnt - 1, ret = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (norep[mid].first <= x) {
            ret = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ret;
}

int main()
{
    while (~scanf("%d", &n), n) {
        for (int i = 1; i <= n; i ++) {
            scanf("%lld", &a[i]);
        }

        long long ans = 1e15 + 10;
        int anscnt = 0;
        int k = n / 2;
        int lim = 1 << k;
        for (int pat = 0; pat < lim; pat ++) {
            sum[pat].first = 0;
            int tmp = pat;
            int i = 1, cnt = 0;
            while (tmp) {
                if (tmp & 1) {
                    sum[pat].first += a[i];
                    ++ cnt;
                }
                ++ i;
                tmp >>= 1;
            }
            sum[pat].second = cnt;

            if (pat != 0) {
                if (ans > aabs(sum[pat].first) ||
                    (ans == aabs(sum[pat].first) && anscnt > cnt)) {
                    ans = aabs(sum[pat].first);
                    anscnt = cnt;
                }
            }

        }
        sort(sum, sum + lim);
        ncnt = 1;
        norep[0] = sum[0];

        for (int i = 1; i < lim; i ++) {
            if (sum[i].first != sum[i - 1].first) {
                norep[ncnt ++] = sum[i];
            }
        }


        int lim2 = 1 << (n - k);
        for (int pat = 1; pat < lim2; pat ++) {
            int tmp = pat;
            int cnt = 0, i = 1;
            long long s = 0;
            while (tmp) {
                if (tmp & 1) {
                    s += a[k + i];
                    ++ cnt;
                }
                ++ i;
                tmp >>= 1;
            }
            long long fd = bins(-s);
            if (aabs(norep[fd].first + s) < ans ||
                (aabs(norep[fd].first + s) == ans && norep[fd].second + cnt < anscnt)) {
                    ans = aabs(norep[fd].first + s);
                    anscnt = norep[fd].second + cnt;
            }
            if ((fd + 1 < ncnt) && (aabs(norep[fd + 1].first + s) < ans ||
                (aabs(norep[fd + 1].first + s) == ans && norep[fd + 1].second + cnt < anscnt))) {
                    ans = aabs(norep[fd + 1].first + s);
                    anscnt = norep[fd + 1].second + cnt;
            }
        }
        printf("%lld %d\n", ans, anscnt);
    }
    return 0;
}




