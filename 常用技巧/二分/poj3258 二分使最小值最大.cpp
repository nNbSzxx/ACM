#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 5e4 + 10;

int ll, n, m;
int a[MAX], keep[MAX];

bool check(int mid)
{
    int cnt = 0, last = 0;
    memset(keep, -1, sizeof keep);
    for (int i = 1; i <= n; i ++) {
        if (a[i] - last < mid) {
            keep[i] = 0;
            ++ cnt;
            if (cnt > m) {
                return false;
            }
        } else {
            last = a[i];
        }
    }
    for (int i = n; i >= 1; i --) {
        if (!keep[i]) {
            continue;
        }
        if (ll - a[i] < mid) {
            ++ cnt;
        } else {
            break;
        }
    }
    if (cnt > m) {
        return false;
    } else {
        return true;
    }
}

int bins()
{
    int l = 0, r = ll, ret = 0;
    while (l <= r) {

        int mid = (l + r) >> 1;
        if (check(mid)) {
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
    while (~scanf("%d%d%d", &ll, &n, &m)) {
        a[0] = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        int ans = bins();
        printf("%d\n", ans);
    }
    return 0;
}
