#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 10;
int n, m, k;
long long a[MAX][6], b[MAX][6];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= k; j ++) {
                scanf("%lld", &a[i][j]);
            }
        }
        for (int i = 1; i <= m; i ++) {
            for (int j = 0; j <= k; j ++) {
                scanf("%lld", &b[i][j]);
            }
            b[i][0] = -b[i][0];
        }
        long long ans = 0, minn, maxx, t;
        for (int s=0; s<(1<<5); s++) {
            minn = INF, maxx = -INF;
            for (int i=0; i<n; i++) {
                t = 0;
                for (int j=0; j<5; j++)
                    if ((1<<j) & s) t += a[i][j];
                    else t -= a[i][j];
                mi = min(mi, t);
                mx = max(mx, t);
            }
            ans = max(ans, mx-mi);
        }
    }
    return 0;
}
