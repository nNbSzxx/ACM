#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 43;
int dp[MAX][MAX][MAX][MAX][2];
int n, m;
int s[MAX][MAX];

int dfs(int lx, int rx, int ly, int ry, int op)
{
    if (dp[lx][rx][ly][ry][op] != -1) {
        return dp[lx][rx][ly][ry][op];
    }
    if (lx > rx || ly > ry) {
        return 0;
    }
    int vis[410];
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (((i + j) & 1) == op) {
                int x = i + j;
                int y = j - i + n;
                if (x >= lx && x <= rx && y >= ly && y <= ry) {
                    if (s[i][j] == 'L') {
                        vis[dfs(lx, x - 1, ly, ry, op) ^ dfs(x + 1, rx, ly, ry, op)] = 1;
                    } else if (s[i][j] == 'R') {
                        vis[dfs(lx, rx, ly, y - 1, op) ^ dfs(lx, rx, y + 1, ry, op)] = 1;
                    } else {
                        vis[dfs(lx, x - 1, ly, y - 1, op) ^ dfs(lx, x - 1, y + 1, ry, op) ^
                            dfs(x + 1, rx, ly, y - 1, op) ^ dfs(x + 1, rx, y + 1, ry, op)] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; ; i ++) {
        if (!vis[i]) {
            return dp[lx][rx][ly][ry][op] = i;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            scanf(" %c", &s[i][j]);
        }
    }
    /*
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            printf("%c", s[i][j]);
        }
        puts("");
    }
    */
    if (dfs(2, n + m, 1, n + m - 1, 0) ^ dfs(2, n + m, 1, n + m - 1, 1)) {
        puts("WIN");
    } else {
        puts("LOSE");
    }

    return 0;
}
