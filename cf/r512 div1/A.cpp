#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    long long n1 = n, m1 = m, k1 = k;
    long long g1 = __gcd(n, k);
    n /= g1;
    k /= g1;
    long long g2 = __gcd(m, k);
    m /= g2;
    k /= g2;
    if (k > 2) {
        puts("NO");
        return 0;
    }
    puts("YES");
    if (k == 1) {
        if (n * 2 <= n1) {
            n *= 2;
        } else {
            m *= 2;
        }
    }
    cout << "0 0" << endl
         << n << " 0" << endl
         << "0 " << m << endl;
    return 0;
}

