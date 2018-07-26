#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 10;
int a[MAX], ps, ns;
char c;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int n, k;
        ps = ns = 0;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i ++) {
            scanf(" %c", &c);
            if (c == 'N' || c == 'L') ps += a[i];
            if (c == 'N' || c == 'D') ns -= a[i];
        }
        if (k >= ns && k <= ps) {
            puts("yes");
        } else {
            puts("no");
        }
    }

}
