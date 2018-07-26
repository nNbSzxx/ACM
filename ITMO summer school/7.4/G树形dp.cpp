#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
const int  MAX =5e4 + 10;

struct edge {
    int v, nt;
} e[MAX * 2];
int head[MAX], cnt;
long long dp[MAX][510];
long long ans = 0;
int n, k;

void init()
{
    cnt = 1;
    memset(head, 0, sizeof(head));
    memset(dp, 0, sizeof(dp));
    return ;
}
void add(int u, int v)
{
    e[cnt].v = v;
    e[cnt].nt = head[u];
    head[u] = cnt ++;
    return ;
}
void dfs(int u, int fa)
{
    dp[u][0] = 1;
    for (int i = head[u]; i; i = e[i].nt) {
        if (e[i].v != fa) {
            dfs(e[i].v, u);
            for (int j = 0; j <= k; j ++) {
                dp[u][j + 1] += dp[e[i].v][j];
            }
        }
    }
    ans += dp[u][k];
    long long temp = 0;
    for (int i = head[u]; i; i = e[i].nt) {
        if (e[i].v != fa) {
            for (int j = 1; j < k; j ++) {
                temp += dp[e[i].v][j - 1] * (dp[u][k - j] - dp[e[i].v][k - j - 1]);
            }
        }
    }
    ans += temp / 2;
}
int main()
{
    int u, v;
    cin >> n >> k;
    init();
    for (int i = 1; i < n; i ++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, -1);
	cout << ans << endl;
    return 0;
}

