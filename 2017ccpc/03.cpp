#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int g[10][10];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        memset(g, 0, sizeof g);
        int a;
        for (int i = 1; i < n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                scanf("%d", &a);
                if (n < 6) {
                    g[i][j] = g[j][i] = a;
                }
            }
        }
        if (n >= 6) {
            puts("Bad Team!");
            continue;
        }
        int flag = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                for (int k = j + 1; k <= n; k ++) {
                    if (g[i][j] && g[i][k] && g[j][k]) {
                        flag = 1;
                    }
                }
            }
        }
        if (flag) {
            puts("Bad Team!");
        } else {
            puts("Great Team!");
        }
    }
}
