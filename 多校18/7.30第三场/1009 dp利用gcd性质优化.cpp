#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 102;
const int MOD = 1e9 + 7;
long long v[MAX];
int l[MAX], r[MAX];
int dp[2][MAX][MAX][MAX];
int g[MAX][MAX];
vector<int> fac[MAX];
int n, m;

void init()
{
    for (int i = 1; i < MAX; i ++) {
        for (int j = 1; j < MAX; j ++) {
            g[i][j] = __gcd(i, j);
        }
    }
    for (int i = 1; i < MAX; i ++) {
        for (int j = i; j < MAX; j += i) {
            fac[j].push_back(i);
        }
    }
}

long long qkp(long long base, long long r)
{
    long long ret = 1;
    while (r) {
        if (r & 1) {
            ret = (ret * base) % MOD;
        }
        base = (base * base) % MOD;
        r >>= 1;
    }
    return ret;
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        int tims = 0;
        for (int i = 1; i <= n; i ++) {
            int a;
            scanf("%d", &a);
            if (a == 0) {
                l[i] = 1;
                r[i] = m;
                ++ tims;
            } else {
                l[i] = r[i] = a;
            }
        }
        for (int i = 1; i <= m; i ++) {
            scanf("%lld", &v[i]);
        }
        memset(dp, 0, sizeof dp);
        for (int i = l[3]; i <= r[3]; i ++) {
            for (int j = l[2]; j <= r[2]; j ++) {
                for (int k = l[1]; k <= r[1]; k ++) {
                    dp[0][i][g[i][j]][g[g[i][j]][k]] ++;
                }
            }
        }
        int w = 0;
        for (int i = 4; i <= n; i ++) {
            w ^= 1;
            for (int x = 1; x <= m; x ++) {
                for (int y, yy = 0; yy < fac[x].size(); yy ++) {
                    y = fac[x][yy];
                    for (int z, zz = 0; zz < fac[y].size(); zz ++) {
                        z = fac[y][zz];
                        if (dp[w ^ 1][x][y][z] == 0) {
                            continue;
                        }
                        for (int j = l[i]; j <= r[i]; j ++) {
                            dp[w][j][g[j][x]][g[j][y]] =
                                (1LL * dp[w][j][g[j][x]][g[j][y]] + 1LL * dp[w ^ 1][x][y][z] * v[g[j][z]]) % MOD;
                        }
                        dp[w ^ 1][x][y][z] = 0;
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i <= m; i ++) {
            for (int j, jj = 0; jj < fac[i].size(); jj ++) {
                j = fac[i][jj];
                for (int k, kk = 0; kk < fac[j].size(); kk ++) {
                    k = fac[j][kk];
                    ans = (ans + dp[w][i][j][k]) % MOD;
                }
            }
        }
        long long inv = qkp(m, MOD - 2);
        for (int i = 1; i <= tims; i ++) {
            ans = (ans * inv) % MOD;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
