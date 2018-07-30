#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int cnt[33];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        memset(cnt, 0, sizeof cnt);
        scanf("%d", &n);
        int w;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &w);
            int j = 0;
            while (w) {
                if (w & 1) {
                    ++ cnt[j];
                }
                w >>= 1;
                j ++;
            }
        }
        int u, v;
        for (int i = 1; i < n; i ++) {
            scanf("%d%d", &u, &v);
        }
        int flag = 0;
        for (int i = 31; i >= 0; i --) {
            if (cnt[i] & 1) {
                puts("Q");
                flag = 1;
                break;
            }
        }
        if (!flag) {
            puts("D");
        }
    }
    return 0;
}
