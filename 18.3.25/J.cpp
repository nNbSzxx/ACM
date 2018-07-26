#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
long long a[3], b[3];
int n;

int main()
{
    while (~scanf("%d", &n)) {
        memset(a, 0 , sizeof a);
        memset(b, 0, sizeof b);
        for (int i = 0; i < n; i ++) {
            int t;
            scanf("%d", &t);
            a[i % 3] += t;
        }
        for (int i = 0; i < n; i ++) {
            int t;
            scanf("%d", &t);
            b[i % 3] += t;
        }
        long long ans[3];
        memset(ans ,0, sizeof ans);
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                ans[(i + j) % 3] += a[i] * b[j];
            }
        }
        for (int i = 1; i < 3; i ++) {
            printf("%lld ", ans[i]);
        }
        printf("%lld\n", ans[0]);
    }
}
