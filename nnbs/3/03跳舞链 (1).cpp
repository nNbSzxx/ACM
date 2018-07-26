#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 5e5 +10;
int loc[MAX], l[MAX], r[MAX], a[MAX];
int f[MAX], b[MAX];
int n, k;

void del(int x)
{
    if (x == 1) {
        l[r[x]] = l[x];
    } else if (x == n) {
        r[l[x]] = r[x];
    } else {
        l[r[x]] = l[x];
        r[l[x]] = r[x];
    }
    l[x] = r[x] = 0;
}

int main()
{
    //freopen("1003.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t --) {

        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            loc[a[i]] = i;
            l[i] = i - 1;
            r[i] = i + 1;
        }
        long long ans = 0;
        for (int i = 1; i <= n - k + 1; i ++) {
            int p = loc[i];
            int lb = 0, lf = 0;
            for (int j = p, t = 0; t <= k && j <= n && j >= 1; t ++, j = r[j]) {
                b[lb ++] = j;
            }
            b[lb] = n + 1;
            for (int j = p, t = 0; t <= k && j >= 1; t ++, j = l[j]) {
                f[lf ++] = j;
            }
            f[lf] = 0;
            for (int j = 0; j < lf && j < k; j ++) {
                if (lb - 1 < k - j - 1)
                    continue;
                int bn = b[k - j] - b[k - j - 1];
                int fn = f[j] - f[j + 1];
                ans += 1LL * bn * fn * i;
            }
            del(p);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
