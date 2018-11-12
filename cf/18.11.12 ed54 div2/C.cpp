#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 1005;
int d;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &d);

        double l = d / 2.0, r = d;
        for (int i = 0; i < MAX; i ++) {
            double a = (l + r) / 2.0;
            double b = d - a;
            if (a * b < d) {
                r = a;
            } else {
                l = a;
            }
        }
        if (abs(l * (d - l) - d) > 1e-6) {
            puts("N");
            continue;
        } else {
            printf("Y ");
            printf("%.9f %.9f\n", l, d - l);
        }

    }
    return 0;
}
