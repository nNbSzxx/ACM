#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int times = n / k;
    if (n % k) ++ times;
    int amount1 = times * t;
    int left = amount1 - d;
    if (left > t) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

