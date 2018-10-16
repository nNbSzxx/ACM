#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char s[15];
char flag[15];

bool check(int mid)
{
    printf("%d %d\n", mid, mid);
    fflush(stdout);
    scanf(" %s", s);
    if (!strcmp(s, flag)) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int l = 1, r = 1e9;
    puts("0 0");
    fflush(stdout);
    scanf(" %s", flag);

    int mid = 0;
    for (int i = 1; i < n; i ++) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d %d %d %d\n", l, l - 1, l - 1, l);
    return 0;
}
