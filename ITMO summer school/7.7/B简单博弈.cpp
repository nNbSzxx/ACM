#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    string s[1005];
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
    }
    string ss;
    for (int i = 1; i <= m; i ++) {
        cin >> ss;
        int flag = 0;
        for (int j = 1; j <= n; j ++) {
            if (ss == s[j]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            sum ++;
        }
    }
    if (n > m) {
        cout << "YES" << endl;
    } else if (n < m) {
        cout << "NO" << endl;
    } else {
        if (sum & 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
