#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

bool isprime(int x)
{
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << 3 << endl;
        return 0;
    }
    if (n & 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= 1000; i ++) {
        if (!isprime(i * n + 1)) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
