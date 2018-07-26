#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int t;
    long long n, m;
    cin >> t;
    while (t --) {
        cin >> n >> m;
        long long ans;
        if (m >= n * (n - 1) / 2) {
            ans = 1LL * n * (n - 1);
        } else if (m >= n - 1) {
            ans = 2LL * (n - 1 + (n - 1) * (n - 2)) - (m - n + 1) * 2;
        } else {
            ans = 2LL * (m + m * (m - 1) + (m + 1) * (n - m - 1) * n) + (n - m - 1) * (n - m - 2) * n;
        }
        cout << ans << endl;
    }
    return 0;
}
