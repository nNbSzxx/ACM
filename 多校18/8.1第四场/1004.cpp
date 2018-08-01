#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 10;
int w[MAX];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int n, m;
        scanf("%d%d", &n, &m);
        int u, v;
        for (int i = 1; i <= n; i ++) {
            scanf("%d%d", &u, &v);
            w[i] = v + 1;
        }
        sort (w + 1, w + 1 + n);
        long long cur = 1;
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            cur = cur * w[i];
            if (cur <= m) {
                ans = i;
            } else {
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
