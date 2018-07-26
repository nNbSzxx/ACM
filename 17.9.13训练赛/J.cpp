#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10];
    while (~scanf("%d%d%d", &a[1], &a[2], &a[3])) {
        long long ans = 0;
        sort(a + 1, a + 1 + 3);
        int cnt = 0;
        for (int i = 1; i <= 3; i ++) {
            if (a[i] == 1) {
                cnt ++;
            } else if (a[i] >= 2) {
                cnt += 2;
            }
        }
        long long sum = 0;
        for (int i = 1; i <= 3; i ++) {
            sum += a[i];
        }
        for (int i = 1; i <= cnt; i ++) {
            ans += i - 1;
        }
        ans = ans + (sum - cnt) * cnt;
        printf("%lld\n", ans);
    }

}
