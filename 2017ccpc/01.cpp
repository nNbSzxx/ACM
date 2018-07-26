#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    const int k = 20;
    int n = 20, m = 0, cur = 21;
    int div = 1;
    int g[210][210];
    memset(g, 0, sizeof g);
    while (div <= 20) {
        n += k / div;
        for (int i = cur; i <= cur + k / div; i ++) {
            for (int j = 21; j <= k / div * div; j ++) {
                g[i][j] = g[j][i] = 1;
            }
        }
        cur += k / div;
    }
}
