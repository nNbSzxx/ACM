#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    int n, m, k;
    cin >> k >> n >> m;
    int cnt = 0;
    for (int i = 1 ; i <= k ; i ++) {
        cin >> s;
        if (s == "Mars") {
            ++ cnt;
        }
    }
    int ex = k - cnt;
    int ans = 0;
    if (ex < m) {
        ans += m - ex;
        k += m - ex;
    }
    k -= m;
    if (k < n) {
        ans += n - k;
    }
    cout << ans << endl;
}
