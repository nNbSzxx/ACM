#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 10;
const int MOD = 256;
int n;
char c[MAX];
int op[MAX], id[MAX];
int vis[MAX][256];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        char s[5];
        for (int i = 1; i <= n; i ++) {
            scanf(" %s", s);
            if (!strcmp(s, "add")) {
                c[i] = '+';
                scanf("%d", &op[i]);
            } else if (!strcmp(s, "beq")) {
                c[i] = '=';
                scanf("%d%d", &op[i], &id[i]);
            } else if (!strcmp(s, "bne")) {
                c[i] = '!';
                scanf("%d%d", &op[i], &id[i]);
            } else if (!strcmp(s, "blt")){
                c[i] = '<';
                scanf("%d%d", &op[i], &id[i]);
            } else {
                c[i] = '>';
                scanf("%d%d", &op[i], &id[i]);
            }
        }

        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= 255; j ++) {
                vis[i][j] = 0;
            }
        }
        int v = 0, i = 1;
        bool ok = true;
        while (i <= n) {
            if (vis[i][v]) {
                ok = false;
                break;
            }
            vis[i][v] = 1;
            if (c[i] == '+') {
                v = (op[i] + v) % MOD;
                ++ i;
            } else if (c[i] == '=') {
                if (v == op[i]) {
                    i = id[i];
                } else {
                    i ++;
                }
            } else if (c[i] == '!') {
                if (v != op[i]) {
                    i = id[i];
                } else {
                    i ++;
                }
            } else if (c[i] == '<') {
                if (v < op[i]) {
                    i = id[i];
                } else {
                    i ++;
                }
            } else {
                if (v > op[i]) {
                    i = id[i];
                } else {
                    i ++;
                }
            }
        }
        if (ok) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
