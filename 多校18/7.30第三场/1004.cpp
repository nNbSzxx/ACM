#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            puts("5");
        } else {
            printf("%d\n", n + 5);
        }
    }
    return 0;
}
