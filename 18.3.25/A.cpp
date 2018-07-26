#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000 + 5;
int a[MAX], b[MAX], dif[MAX * MAX], cnt = 0;
unordered_map<int, int> mp;

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= m; i ++) {
            scanf("%d", &b[i]);
        }
        cnt = 0;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (b[i] >= a[j])
                    dif[cnt ++] = b[i] - a[j];
                else
                    break;
            }
        }
        sort(dif, dif + cnt);
        int times = -1, ans = -1, curans = dif[0], curtimes = 1;
        for (int i = 1; i < cnt; i ++) {
            if (curans == dif[i]) {
                ++ curtimes;
            } else {
                if (curtimes > times || (curtimes == times && curans < ans)) {
                    times = curtimes;
                    ans = curans;
                }
                curans = dif[i];
                curtimes = 1;
            }
        }
        if (curtimes > times || (curtimes == times && curans < ans)) {
            times = curtimes;
            ans = curans;
        }
        printf("%d\n", ans);
    }

    return 0;
}
