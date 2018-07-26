#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e4 +10;

int main()
{
    int t, n, m;
    long long b[MAX];
    scanf("%d", &t);
    while (t -- ) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= m; i ++) {
            scanf("%lld", b + i);
        }
        int flag = 0;
        for (int i = 1; i <= m; i ++) {
            while (b[i]) {
                b[i] --;
                if (flag) {
                    printf(" ");
                } else {
                    flag = 1;
                }
                printf("%d", i);
                for (int j = 2 * i; j <= m; j ++) {
                    if (b[j] && b[j - i]) {
                        b[j] -= b[j - i];
                    }
                }
            }
        }
        puts("");
    }

    return 0;
}
