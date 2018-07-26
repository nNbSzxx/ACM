#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 60;

int main()
{
    int n;
    cin >> n;
    int x, y;
    cout << "YES" << endl;
    for (int i = 1 ; i <= n; i ++) {
        cin >> x >> y;
        if ((x & 1) && (y & 1)) {
            cout << 1 << endl;
        }
        if ((x & 1) && !(y & 1)) {
            cout << 2 << endl;
        }
        if (!(x & 1) && (y & 1)) {
            cout << 3 << endl;
        }
        if (!(x & 1) && !(y & 1)) {
            cout << 4 << endl;
        }
        cin >> x >> y;
    }
    return 0;
}
