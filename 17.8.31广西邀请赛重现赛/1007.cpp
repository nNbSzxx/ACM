#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 15;
int n, cnt[MAX];

int main()
{
    while (~scanf("%d", &n)) {
        memset(cnt, 0, sizeof cnt);
        int t;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &t);
            ++ cnt[t + 2];
        }
        int ans = 0;
        for (int i = 1; i <= n + 2; i ++) {
            if (cnt[i] == 0) continue;
            if (cnt[i] && cnt[i - 1] && cnt[i - 2]) {
                cnt[i] -= 1;
                cnt[i - 1] -= 1;
                ans += 1;
            }
            if (cnt[i] >= 2) {
                ans += cnt[i] >> 1;
                cnt[i] &= 1;
            }
        }
        printf("%d\n", ans);
    }
}
