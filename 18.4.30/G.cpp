#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("grave.in", "r", stdin);
    freopen("grave.out", "w", stdout);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    int w, h;
    scanf("%d%d", &w, &h);
    int W = x2 - x1;
    int H = y2 - y1;
    int w1 = x3 - x1;
    int h1 = y3 - y1;
    if (w <= w1 && h <= H) {
        puts("Yes");
        return 0;
    }
    if (h <= h1 && w <= W) {
        puts("Yes");
        return 0;
    }
    w1 = x2 - x4;
    h1 = y2 - y4;
    if (w <= w1 && h <= H) {
        puts("Yes");
        return 0;
    }
    if (h <= h1 && w <= W) {
        puts("Yes");
        return 0;
    }
    puts("No");
    return 0;
}
