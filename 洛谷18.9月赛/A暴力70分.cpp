#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
unsigned long long n, k;

int main()
{
    scanf("%llu%llu", &k, &n);
    unsigned long long sum = 0;
    for (int i = 1; ; i ++) {
        sum = sum * 10 + 1;
        sum = sum % n;
        if (sum == k) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
