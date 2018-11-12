#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 2e5 + 10;

int vis[MAX], prime[MAX], cnt;

int main()
{
    cnt = 0;
    long long n;
    scanf("%lld", &n);
    memset(vis, 0, sizeof vis);
    for (int i = 2; i < MAX; i ++) {
        if (!vis[i]) {
            prime[cnt ++] = i;
            for (int j = i * 2; j < MAX; j += i) {
                vis[j] = 1;
            }
        }
    }

    long long p = -1;
    for (int i = 0; i < cnt; i ++) {
        if (n % prime[i] == 0) {
            p = prime[i];
            break;
        }
    }
    if (p == -1) {
        p = n;
    }
    if (p == 2)
        printf("%lld\n", n / p);
    else
        printf("%lld\n", 1LL + (n - p) / 2LL);
    return 0;
}
