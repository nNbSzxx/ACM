#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;;

long long n;

int main()
{
    int ans = 0;
    scanf("%lld", &n);
    while (n) {
        int d = n % 10;
        n /= 10;
        ans += d;
        if (d != 9 && n != 0) {
            ans += 10;
            n --;
        }
    }
    printf("%d\n", ans);
    return 0;
}
