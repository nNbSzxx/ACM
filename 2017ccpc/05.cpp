#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        double n;
        scanf("%lf", &n);

        int l = ceil(sqrt(n / 2.0));
        if (2 * (l) * (l - 1) >= n) {
            if (2 * (l - 1) * (l - 1) + l - 0.5 >= n) {
                printf("%d\n", 4 * l - 3);
            } else {
                printf("%d\n", 4 * l - 2);
            }
        } else {
            if (2 * l * (l - 1) + l - 0.5 >= n) {
                printf("%d\n", 4 * l - 1);
            } else {
                printf("%d\n", 4 * l);
            }
        }
    }
    return 0;
}
