#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 101;
long long a[MAX];

int main()
{
    for (int n = 1; n <= 110; ++n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j < i; ++j)
                if (__gcd(i + j, i - j) == 1) ++ ans;
        cout << ans << ' ';
        if (n % 5 == 0) {
            puts("");
        }
    }

    return 0;
}
