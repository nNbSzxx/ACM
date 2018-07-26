#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];

int main()
{
    int t;
    cin >> t;
    while(t --) {
        int n,m;
        scanf("%d%d", &n, &m);
        for(int i = 1;i <= n;i++)
            scanf("%d", &a[i]);
        for(int k = 0; (1 << k) <= m; k++) {
            if((m >> k) & 1) {
                for(int i = (1 << k) + 1 ; i <= n; i ++) {
                    a[i] ^= a[i - (1 << k)];
                }
            }
        }
        printf("%d", a[1]);
        for(int i = 2; i <= n; i ++) {
            printf(" %d", a[i]);
        }
        puts("");
    }
    return 0;
}
