#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    ans += a;
    while (a >= b) {
        ans += a / b;
        a = a / b + a % b;
    }
    cout << ans << endl;
    return 0;
}
