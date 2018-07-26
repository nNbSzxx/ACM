#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100000 + 10;

int main()
{
    int n, k;
    cin >> n >> k;
    int factor[MAX], times[MAX];
    memset(times, 0 ,sizeof(times));
    int cnt = 0, sum = 0;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            factor[++ cnt] = i;
            while (n % i == 0) {
                n /= i;
                times[cnt] ++;
                sum ++;
            }
        }
        ++ i;
    }
    if (n > 1) {
        factor[++ cnt] = n;
        times[cnt] ++;
        sum ++;
    }
    if (k > sum) {
        cout << -1 << endl;
    } else {
        int j = 1, a1 = 1;
        for (int i = 1; i <= sum - k + 1; i ++) {
            if (times[j] == 0) ++ j;
            a1 *= factor[j];
            times[j] --;
        }
        cout << a1;
        if (times[j] == 0) j ++;
        for (int i = j; i <= cnt; i ++) {
            while (times[i] > 0) {
                cout << " " << factor[i];
                times[i] --;
            }
        }
        cout << endl;
    }
    return 0;
}


