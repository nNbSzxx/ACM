#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n & 1) {
        cout << n / 2 << endl;
    } else {
        cout << n / 2 - 1 << endl;
    }
    return 0;
}


