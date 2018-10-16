#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 10;
const double EPS = 1e-6;

int n;
int x[MAX], y[MAX];

bool check(double mid)
{
    double l = -1e18, r = 1e18;
    for (int i = 1; i <= n; i ++) {
        if (y[i] > 2 * mid) {
            return false;
        }
        //double dis = y[i] - mid;
        double del = sqrt(y[i] * (2 * mid - y[i]));
        l = max(l, x[i] - del);
        r = min(r, x[i] + del);
    }
    return l < r;
}

double bins()
{
    double l = 0, r = 1e18;
    for (int i = 0; i < 300; i ++) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main()
{
    scanf("%d", &n);
    int vis[2] = {0, 0};
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &x[i], &y[i]);
        if (y[i] > 0) {
            vis[0] = 1;
        } else if (y[i] < 0) {
            vis[1] = 1;
            y[i] = -y[i];
        }
    }
    if (vis[0] && vis[1]) {
        puts("-1");
        return 0;
    }
    printf("%.8f\n", bins());

    return 0;
}
