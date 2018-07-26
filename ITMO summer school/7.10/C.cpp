#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int a[200];
    cin >> n;
    for (int i = 1 ; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a  +1,  a+ 1 + n);
    int sum = 0, cnt = 0;
    const int S = 710;
    int i = 1;
    for (; i <= n && sum <= S; i ++) {
        sum += a[i];
        ++ cnt;
    }
    if (sum > S) {
        sum -= a[i - 1];
        -- cnt;
    }
    int p = 0, left = 350;
    for (int i = 1; i <= cnt; i ++) {
        left -= a[i];
        if (left < 0) {
            p -= left;
        }
    }
    cout << cnt << " " << p << endl;
    return 0;
}

