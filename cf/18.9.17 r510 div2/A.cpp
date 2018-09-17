#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int a[200];
int sum;

bool check(int mid)
{
    int t = m;
    for (int i = 1; i <= n; i ++) {
        if (a[i] > mid) {
            return false;
        } else {
            t -= (mid - a[i]);
        }
    }
    return t <= 0;
}

int bins()
{
    int l = 0, r = 20010, mid, ret;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ret = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ret;
}

int main()
{

    scanf("%d%d", &n, &m);
    int minn = 999, maxx = -1;
    sum = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        sum += a[i];
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }
    printf("%d %d\n", bins(), maxx + m);
    return 0;
}
