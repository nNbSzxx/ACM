#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX = 1e5 + 10;
int n, m, k;
int a[MAX];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    while (m --) {
        int l, r;
        scanf("%d%d", &l, &r);
        long long ans = 0;
        for (int i = l; i <= r; i ++) {
            for (int j = l; j < i; j ++) {
                if (__builtin_popcount(a[i] ^ a[j]) == k) {
                    ++ ans;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
