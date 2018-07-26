#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;

long long p(long long base, int r)
{
    long long ret = 1;
    while (r) {
        if (r & 1) {
            ret = ret * base % MOD;
        }
        base = (base * base) % MOD;
        r >>= 1;
    }
    return ret;
}

int main()
{
    char s[MAX];
    scanf("%s", s);
    int len = strlen(s);
    int suma = 0;
    long long ans = 0;
    for (int i = 0; i < len; i ++) {
        if (s[i] == 'a') {
            suma ++;
        } else {
            ans = (ans + p(2, suma) - 1) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}

