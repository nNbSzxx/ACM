#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 10;
int h[MAX], inch[MAX], dech[MAX];

int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &h[i]);
    }

    h[0] = inch[0] = dech[0] = 0;
    h[n + 1] = inch[n + 1] = dech[n + 1] = 0;

    for (int i = 1; i <= n; i ++) {
        if (h[i] > inch[i - 1]) {
            inch[i] = inch[i - 1] + 1;
        } else {
            inch[i] = h[i];
        }
    }

    for (int i = n; i >= 1; i --) {
        if (h[i] > dech[i + 1]) {
            dech[i] = dech[i + 1] + 1;
        } else {
            dech[i] = h[i];
        }
    }

    int maxx = -1, m;
    for (int i = 1; i <= n; i ++) {
        m = min(inch[i], dech[i]);
        maxx = max(m, maxx);
    }
    printf("%d\n", maxx);
//    for (int i = 1; i <= n; i ++) {
//        printf("%d %d %d\n", h[i], inch[i], dech[i]);
//    }
    return 0;
}

