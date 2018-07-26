#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 2000;
    int dif = 0;
    int odd = 1;
    int ans = 2000 + 1999;
    while (1) {
        //printf("%d\n", n);
        dif += odd + 1;
        odd += 4;
        if (n - dif <= 0)
            break;
        ans += n - dif;
    }
    n = 1999;
    dif = 0;
    odd = 3;
    while (1) {
        dif += odd + 1;
        odd += 4;
        if (n - dif <= 0)
            break;
        ans += n - dif;
    }
    printf("%d\n", ans);
    return 0;
}
