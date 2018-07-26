#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int n, a;
        int cnt0 = 0, cnt1 = 0;
        scanf("%d", &n);
        for (int i = 1 ; i <= n; i ++) {
            scanf("%d", &a);
            if (a & 1) cnt1 ++;
            else cnt0 ++;
        }
        if (cnt1 > cnt0) {
            puts("2 1");
        } else {
            puts("2 0");
        }
    }
    return 0;
}
