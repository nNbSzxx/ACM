#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    int x[3], y[3];
    for (int i = 0; i < 3; i ++) {
        cin >> x[i] >> y[i];
    }
    cout << 3 << endl;
    int disx = x[0] - x[1];
    int disy = y[0] - y[1];
    cout << x[2] + disx << " " << y[2] + disy << endl;
    cout << x[2] - disx << " " << y[2] - disy << endl;
    disx = x[1] - x[2];
    disy = y[1] - y[2];
    cout << x[0] + disx << " " << y[0] + disy << endl;
    return 0;
}

