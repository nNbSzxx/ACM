#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;

int main()
{
    int t, n, k, a[MAX];
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int ans = 1;
        for (int i = n - 2; i >= 0; i --) {
            if (a[i + 1] - a[i] <= k) {
                ++ ans;
            } else {
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
