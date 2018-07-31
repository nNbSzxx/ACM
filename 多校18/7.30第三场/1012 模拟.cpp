#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char s[1010][1010];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        memset(s, 0, sizeof s);
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int len = b * 2 + c * 2 + 1;
        int wid = b * 2 + a * 2 + 1;

        for (int i = 1, cnt = 2 * b; i <= b * 2; i ++, cnt --) {
            for (int j = 1; j <= cnt; j ++) {
                s[i][j] = '.';
            }
        }


        for (int i = len, cnt = b * 2; i > len - b * 2; i --, cnt --) {
            for (int j = wid; j > wid - cnt; j --) {
                s[i][j] = '.';
            }
        }


        for (int i = b * 2 + 1; i <= len; i ++) {
            for (int j = 1; j <= a * 2 + 1; j ++) {
                if (i & 1) {
                    if (j & 1) {
                        s[i][j] = '+';
                    } else {
                        s[i][j] = '-';
                    }
                } else {
                    if (j & 1) {
                        s[i][j] = '|';
                    } else {
                        s[i][j] = '.';
                    }
                }
            }
        }


        for (int i = 1, cnt = 2 * b + 1; i <= 2 * b; i ++, cnt --) {
            for (int j = cnt; j <= cnt + 2 * a; j ++) {
                if (i & 1) {
                    if (j & 1) {
                        s[i][j] = '+';
                    } else {
                        s[i][j] = '-';
                    }
                } else {
                    if (j & 1) {
                        s[i][j] = '.';
                    } else {
                        s[i][j] = '/';
                    }
                }
            }
        }


        for (int j = 2 * a + 2, cnt = 2 * b + 1; j <= wid; j ++, cnt --) {
            for (int i = cnt; i < cnt + 2 * c; i ++) {
                if (j & 1) {
                    if (i & 1) {
                        s[i][j] = '+';
                    } else {
                        s[i][j] = '|';
                    }
                } else {
                    if (i & 1) {
                        s[i][j] = '.';
                    } else {
                        s[i][j] = '/';
                    }
                }
            }
        }

        for (int i = 1; i <= len; i ++) {
            puts(s[i] + 1);
        }
    }
    return 0;
}
