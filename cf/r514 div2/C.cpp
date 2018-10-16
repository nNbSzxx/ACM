#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1) {
        puts("1");
        return 0;
    }
    int cur = 1;
    while (true) {
        if (n == 2) {
            printf("%d %d", cur, cur * 2);
            break;
        } else if (n == 3) {
            printf("%d %d %d\n", cur, cur, cur * 3);
            break;
        }
        for (int i = 1; i <= (n + 1) / 2; i ++) {
            printf("%d ", cur);
        }
        n /= 2;
        cur *= 2;
    }
    return 0;
}
