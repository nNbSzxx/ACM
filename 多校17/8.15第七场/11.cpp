#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e7 + 20;
int a[MAX] = {0, 1, 2, 2, 1, 1, };

int main()
{

    int i = 6, j = 4, cnt, now = 2;
    while (i <= 1e7 + 1) {
        cnt = a[j];
        while (cnt --) {
            a[i ++] = now;
        }
        ++ j;
        if (now == 2) -- now;
        else ++ now;
    }
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &now);
        printf("%d\n", a[now]);
    }
    return 0;
}
