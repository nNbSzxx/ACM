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
    int xx, yy;
    map<int, int> x, y;

    for (int i = 1;i <= n; i ++) {
        scanf("%d%d", &xx, &yy);
        x[xx + 10000] ++;
        y[yy + 10000] ++;
    }
    unsigned long long sum = 0;
    for (map<int, int>::iterator it = x.begin(); it != x.end(); it ++) {

        for (map<int, int> jt = it + 1; j != x.end(); jt ++) {

            sum += (unsigned long long)((it->first - jt -> first) * (it->first - jt->first)) * (it->second * jt->second);

        }
    }

    for (map<int, int>::iterator it = y.begin(); it != y.end(); it ++) {

        for (map<int, int> jt = it + 1; j != y.end(); jt ++) {

            sum += (unsigned long long)((it->first - jt -> first) * (it->first - jt->first)) * (it->second * jt->second);

        }
    }
    cout << sum << endl;

    return 0;
}

