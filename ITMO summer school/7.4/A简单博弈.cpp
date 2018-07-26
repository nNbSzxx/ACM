#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a;
        if (a % 2 == 0) {
            ++ sum;
        }
        if (sum & 1) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}

