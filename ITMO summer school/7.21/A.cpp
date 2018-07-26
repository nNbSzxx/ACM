#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n -= 10;
    int ans = 0;
    for (int i = 2; i <= 14; i ++) {
        if (i >= 2 && i <= 10) {
            if (n == i) {
                ans += 4;
            }
        } else if (i == 11 || i == 13) {
            if (n == 10) {
                ans += 4;
            }
        } else if (i == 12) {
            if (n == 10) {
                ans += 3;
            }
        } else if (i == 14) {
            if (n == 1 || n == 11) {
                ans += 4;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
