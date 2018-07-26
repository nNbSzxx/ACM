#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
const int MAX = 2e5 + 10;
int isprime[MAX], prime[MAX], mu[MAX], cnt;
int sum[MAX], a[MAX], n;

void mobius(void)
{
    memset(isprime, -1, sizeof isprime);
    cnt = 0;
    isprime[0] = isprime[1] = 0;
    mu[1] = 1;
    for (int i = 1; i < 1e5 + 10; i ++) {
        if (isprime[i]) {
            mu[i] = -1;
            prime[cnt ++] = i;
        }
        for (int j = 0; j < cnt && i * prime[j] < 1e5 + 10; j ++) {
            isprime[i * prime[j]] = 0;
            if (i % prime[j]) mu[i * prime[j]] = - mu[i];
            else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
    return ;
}

long long p(long long base, long long r)
{
    long long ret = 1;
    while (r) {
        if (r & 1) {
            ret = ret * base % mod;
        }
        base = base * base % mod;
        r >>= 1;
    }
    return ret;
}

int main()
{
    mobius();
    int t;
    scanf("%d", &t);
    while (t --) {
        int maxx = -1, minn = 1e5 + 10;
        memset(sum, 0, sizeof sum);
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            ++ sum[a[i]];
            minn = min(minn, a[i]);
            maxx = max(maxx, a[i]);
        }
        for (int i = 2; i < MAX; i ++) {
            sum[i] += sum[i - 1];
        }
        long long ans = 0;
        long long temp;
        for (int i = 2; i <= minn; i ++) {
            if (!mu[i]) continue;
            temp = 1;
            int cnt = 1;
            for (int j = i; j <= maxx; j += i) {
                temp = temp * p(cnt ++, sum[j + i - 1] - sum[j - 1]) % mod;
            }
            ans = (ans - temp * mu[i] + mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
