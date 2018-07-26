#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
const int MAX = 110;

int gcd(int a, int b)
{
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, a[MAX];
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int d = a[n - 1];
    for (int i = n - 2; i >= 0; i --) {
       d = gcd(d, a[i]);
    }
    int cnt = a[n - 1] / d - n;
    if (cnt & 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    return 0;
}

