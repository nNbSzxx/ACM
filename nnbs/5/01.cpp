#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e4 +10;
int a[32][MAX], n, m, q, ans[MAX];

inline void flip(int arr[], int loc)
{
    arr[loc >> 5] ^= (1 << (loc & 31));
}
inline int get(int arr[], int loc)
{
    return !!(arr[loc >> 5] & (1 << (loc & 31)));
}
void xorr(int l, int r)
{
    while ((r - l) & 31) {
        if (get(a[0], r - 1))
            flip(ans, r - l - 1);
        -- r;
    }
    int where = 0;
    while (l & 31) {
        ++ l;
        ++ r;
        ++ where;
    }
    l >>= 5;
    r >>= 5;
    for (int i = l; i < r; i ++) {
        ans[i - l] ^= a[where][i];
    }
}
int main()
{
   // freopen("1001.in", "r", stdin);
    //freopen("1001.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t --) {
        memset(a, 0, sizeof a);
        memset(ans, 0, sizeof ans);
        int temp;
        scanf("%d%d%d", &n, &m, &q);
        int maxn = -1;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &temp);
            maxn = max(maxn, temp);
            for (int j = 0; j < 32; j ++) {
                flip(a[j], temp + j);
            }
        }
        for (int i = 1; i <= m; i ++) {
            scanf("%d", &temp);
            for (int j = 0; j <= maxn; j += temp) {
                xorr(j, min(j + temp, maxn + 1));
            }
        }
        for (int i = 1; i <= q; i ++) {
            scanf("%d", &temp);
            printf("%d\n", get(ans, temp));
        }
    }
    return 0;
}
