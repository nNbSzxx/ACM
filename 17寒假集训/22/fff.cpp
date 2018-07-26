#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 2000;
const int mod = 1e9+7;

int w[MAX], dp[MAX], fac[MAX];

int main()
{
    int t, m, p, k;
    scanf("%d",&t);
    while(t --) {
        memset(dp, 0, sizeof(dp));
        memset(fac, 0, sizeof(fac));
        dp[0] = 1;
        scanf("%d%d",&m,&p);
        for(int i = 0; i < m; i++) {
            scanf("%d",&k);
            k %= p;
            if (k < 0) {
            	k += p;
			}
            w[i] = k;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < p; j++)
                fac[j] = dp[j];
            for(int j = 0; j < p; j++) {
                k = (j + w[i])%p;
                fac[k] += dp[j] % mod;
            }
            for(int j = 0; j < p; j++)
                dp[j] = fac[j] % mod;
        }
        printf("%d\n",dp[0]);
    }
    return 0;
}
