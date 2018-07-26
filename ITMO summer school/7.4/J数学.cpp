#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
const int MAX = 1e4 + 10;

int main()
{
    int n;
    scanf("%d", &n);
    int x, y;
    long long sumx = 0, sumy = 0, sum = 0;
    for (int i = 1;i <= n; i ++) {
        scanf("%d%d", &x, &y);
        sum += (long long)(x * x + y * y) * (n - 1);
        sum -= (x * 2 * (sumx));
        sum -= (y * 2 * (sumy));
        sumx += x;
        sumy += y;
    }


    cout << sum << endl;

    return 0;
}

