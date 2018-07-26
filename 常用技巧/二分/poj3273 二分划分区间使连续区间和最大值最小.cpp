#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;

int a[MAX];
int n, m;

bool check(int mid)
{
    int cnt = 1, amount = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] > mid) {
            return false;
        }
        if (amount + a[i] > mid) {
            amount = a[i];
            ++ cnt;
            if (cnt > m) {
                return false;
            }
        } else {
            amount += a[i];
        }
    }
    return true;
}

int bins()
{
    int l = 1, r = 1e9, ret = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        //printf("%d %d %d\n", l, r, mid);

        if (check(mid)) {
            r = mid - 1;
            ret = mid;
        } else {
            l = mid + 1;
        }
    }
    return ret;
}

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
        }
        int ans = bins();
        printf("%d\n", ans);
    }
    return 0;
}
