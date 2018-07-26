#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 +10;
const long long mod = 1e6 + 3;
int n, a, cnt[35];
long long c[MAX][MAX];

void init()
{
    c[0][0] = 1;
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= 1000; i ++) {
        c[i][i] = c[i][0] = 1;
        for (int j = 1; j < i; j ++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

int main()
{
    init();
    while (~scanf("%d", &n)) {
        memset(cnt, 0, sizeof cnt);
        int high = -1;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a);
            int j;
            for (j = 0; a && j <= 31; j ++) {
                cnt[j] += (a & 1);
                a >>= 1;
            }
            high = max(high, j - 1);
        }
        //for (int i = 0; i <= high; i ++) {
        //    printf("%d ", cnt[i]);
        //}
        //puts("");
        //cout << c[2][1] << endl;
        for (int i = 1; i <= n; i ++) {
            long long ans = 0;
            for (int j = 0; j <= high; j ++) {
                for (int k = 1; k <= cnt[j] && i - k >= 0; k += 2) {
                    ans = (ans + 1LL * c[cnt[j]][k] * c[n - cnt[j]][i - k] % mod * (1 << j)) % mod;
                }
                //cout << ans <<endl;
            }
            printf("%I64d", ans);
            if (i == n) {
                puts("");
            } else {
                printf(" ");
            }
        }
    }
}
