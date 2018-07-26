#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int flag;
    if (k != 1 && k != n) {
        if (n - k > k - 1) {
            for (int i = k; i > 1; i --) {
                cout << "LEFT" << endl;
                flag = 0;
                k = 1;
            }
        } else {
            for (int i = k; i < n; i ++) {
                cout << "RIGHT" << endl;
                flag = 1;
                k = n;
            }
        }
    } else {
        if (k == 1) {
            flag  = 0;
        } else {
            flag = 1;
        }
    }

    if (flag == 0) {
        for (int i = 1; i < n; i ++) {
            cout << "PRINT " << s[i - 1] << endl;
            cout << "RIGHT" << endl;
        }
        cout << "PRINT " << s[n - 1] << endl;
    } else {
        for (int i = n; i > 1; i --) {
            cout << "PRINT " << s[i - 1] << endl;
            cout << "LEFT" << endl;
        }
        cout << "PRINT " << s[0] << endl;
    }

    return 0;
}
