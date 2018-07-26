#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int w, h;
    cin >> w >> h;
    double x = min(1.0 * w, 1.0 * h / 3);
    x = max(x, min(1.0 * h, 1.0 * w / 3));
    x = max(x, min(1.0 * h / 2, 1.0 * w / 2));
    printf("%.6f", x);
    return 0;
}
