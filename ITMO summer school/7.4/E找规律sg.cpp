#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
const int MAX = 110;

int main()
{
    int n, a, ans = 0;
    int sg[70];
    int num = 1;
    for (int i = 0; i <= 60; i += num - 1) {
        for (int j = 0; j < num; j ++) {
            sg[i + j] = num - 1;
        }
        ++ num;
    }
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a;
        ans ^= sg[a];
    }

    if (ans) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}

