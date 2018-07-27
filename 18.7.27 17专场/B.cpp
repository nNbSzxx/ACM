#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    if (n == 1) {
        puts("1");
        return 0;
    } else if (n == 2) {
        puts("2");
        return 0;
    } else if (n == 3) {
        puts("6");
        return 0;
    }
    long long ans;
    if (n & 1) {
        ans = n * (n - 1) * (n - 2);
    } else {
        if (n % 3 == 0) {
            ans = (n - 1) * (n - 2) * (n - 3);
        } else {
            ans = n * (n - 1) * (n - 3);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
