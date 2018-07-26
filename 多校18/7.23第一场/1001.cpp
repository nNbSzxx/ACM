#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int n;
        scanf("%d", &n);
        if (n % 3 == 0) {
            long long fac = n / 3;
            printf("%lld\n", 1LL * fac * fac * fac);
        } else if (n % 4 == 0) {
            long long fac = n / 4;
            printf("%lld\n", fac * fac * fac * 2);
        } else {
            puts("-1");
        }
    }
    return 0;
}
