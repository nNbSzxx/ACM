#include <bits/stdc++.h>
using namespace std;
const double PRE = 1e-6;
double del[11];

int main()
{
    int x, y;
    for (int i = 1; i <= 10; i ++) {
        del[i] = 1.0 / i;
    }
    while (~scanf("%d%d", &x, &y)) {
        if (y < x)  { puts("-1"); continue; }
        double aver = 1.0 * (y + 1 - PRE) / x;
        int ans = x - 1, k;
        double temp = 1;
        for (int i = 1; i <= x; i ++) {
            k = int(aver * i - temp);
            ans += k;
            temp += k;
            temp = temp / i * (i + 1);
            //printf("%d %d %.2f\n", ans, k, temp);
        }
        printf("%d\n", ans);
    }
}
