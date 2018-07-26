#include <cstdio>
using namespace std;
typedef long long LL;
const int MAX = 110;
const LL MOD = 1e9 + 7;
LL dp[MAX][MAX][MAX], f[MAX];
char a[MAX];
int n, len;
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%s", &len, &n, a);
    for (int i = 0; i < len; ++i) dp[a[i] - '0'][i][i] = 1;
    f[0] = f[1] = 2;
    for (int i  = 2; i <= n; ++i) f[i] = f[i - 1] * f[i - 2] % MOD;
    for (int i = 2; i <= n; ++i)
        for (int l = 0; l < len; ++l)
            for (int r = l; r < len; ++r) {
                if (l == 0)
                    dp[i][l][r] = (dp[i][l][r] + f[i - 1] * dp[i - 2][l][r] % MOD) % MOD;
                else
                    dp[i][l][r] = (dp[i][l][r] + dp[i - 2][l][r]) % MOD;
                if (r == len - 1)
                    dp[i][l][r] = (dp[i][l][r] + f[i - 2] * dp[i - 1][l][r] % MOD) % MOD;
                else
                    dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][r]) % MOD;
                for (int k = l; k <= r; ++k)
                    dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][k] * dp[i - 2][k + 1][r] % MOD) % MOD;
            }
    printf("%lld\n", dp[n][0][len - 1]);
    printf("1 1 1 %lld\n", dp[1][0][0]);
    printf("2 1 1 %lld\n", dp[2][0][0]);
    printf("2 2 2 %lld\n", dp[2][1][1]);
    printf("3 1 1 %lld\n", dp[3][0][0]);
    printf("3 2 2 %lld\n", dp[3][1][1]);
    printf("3 1 2 %lld\n", dp[3][0][1]);
	return 0;
}
