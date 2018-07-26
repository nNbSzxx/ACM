#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x == a) {
        cout << 0 << " " << y << " " << n << " " << b << endl;
    } else {
        cout << x << " " << 0 << " " << a << " " << m << endl;
    }
    return 0;
}
