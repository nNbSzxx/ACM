#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MOD = 998244353;
const int MAX = 1e6 + 10;
long long ans[MAX], lf[MAX];
long long l, r, k, sum;
int isprime[MAX], prime[MAX], cnt;

void solve(void)
{
    int i = 0;
    while (i < cnt) {
        if (prime[i] > r) break;
        long long s = l / prime[i] * prime[i];
        if (s < l) s += prime[i];
        long long times;
        while (s <= r) {
            times = 0;
            while (lf[s - l] % prime[i] == 0) {
                lf[s - l] /= prime[i];
                ++ times;
            }
            ans[s - l] = ans[s - l] * (times * k + 1) % MOD;
            s += prime[i];
        }
        ++ i;
    }
}

int main()
{
    cnt = 0;
    memset(isprime, -1, sizeof isprime);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i < MAX; i ++) {
        if (isprime[i]) {
            prime[cnt ++] = i;
            for (int j = i * 2; j < MAX; j += i) {
                isprime[j] = 0;
            }
        }
    }

    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%lld%lld%lld", &l, &r, &k);
        for (int i = 0; i <= r - l; i ++) {
            lf[i] = i + l;
            ans[i] = 1;
        }
        solve();
        sum = 0;
        for (int i = 0; i <= r - l; i ++) {
            if (lf[i] != 1) {
                ans[i] = ans[i] * (k + 1) % MOD;
            }
            sum = (sum + ans[i]) % MOD;
        }
        printf("%lld\n", sum);
    }

    return 0;
}
