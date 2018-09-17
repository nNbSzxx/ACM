#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e3 + 10;
const int INF = 1e8 + 10;

int n;

int main()
{
    scanf("%d", &n);
    int a = INF, b = INF, c = INF;
    int ab = INF, ac = INF, bc = INF;
    int abc = INF;
    for (int i = 1; i <= n; i ++) {
        char s[6];
        int v;
        scanf("%d %s", &v, s);
        int len = strlen(s);
        sort(s, s + len);
        if (!strcmp(s, "A")) {
            a = min(a, v);
        } else if (!strcmp(s, "B")) {
            b = min(b, v);
        } else if (!strcmp(s, "C")) {
            c = min(c, v);
        } else if (!strcmp(s, "AB")) {
            ab = min(ab, v);
        } else if (!strcmp(s, "AC")) {
            ac = min(ac, v);
        } else if (!strcmp(s, "BC")) {
            bc = min(bc, v);
        } else if (!strcmp(s, "ABC")) {
            abc = min(abc, v);
        }
    }
    int ans = INF;
    ans = min(ans, a + b + c);
    ans = min(ans, a + bc);
    ans = min(ans, ac + b);
    ans = min(ans, ab + c);
    ans = min(ans, abc);
    ans = min(ans, ab + bc);
    ans = min(ans, ac + bc);
    ans = min(ans, ab + ac);
    if (ans == INF) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}
