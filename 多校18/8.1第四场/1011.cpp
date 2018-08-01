#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[550];
const int OP = 0;
const int HZERO = 1;
const int NHZERO = 2;
const int NZERO = 3;

bool isOp(char c)
{
    return c == '+' || c == '*';
}

bool isZero(char c)
{
    return c == '0';
}

bool isDig(char c)
{
    return c >= '1' && c <= '9';
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf(" %s", s);
        int len = strlen(s);
        int last = OP;
        int possible = 1;
        for (int i = 0; i < len; i ++) {
            if (s[i] != '?') {
                if (isOp(s[i])) {
                    if (last == OP) {
                        possible = 0;
                        break;
                    } else {
                        last = OP;
                    }
                } else if (isZero(s[i])) {
                    if (last == HZERO) {
                        possible = 0;
                        break;
                    } else if (last == OP) {
                        last = HZERO;
                    } else if (last == NHZERO || last == NZERO) {
                        last = NHZERO;
                    }
                } else if (isDig(s[i])) {
                    if (last == HZERO) {
                        possible = 0;
                        break;
                    } else {
                        last = NZERO;
                    }
                }
            } else {
                // ?
                if (last == HZERO) {
                    s[i] = '+';
                    last = OP;
                } else {
                    s[i] = '1';
                    last = NZERO;
                }
            }
        }
        if (!possible || last == OP) {
            puts("IMPOSSIBLE");
        } else {
            puts(s);
        }
    }

    return 0;
}
