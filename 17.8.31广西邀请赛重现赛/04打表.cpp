#include <bits/stdc++.h>
using namespace std;
int vis[6][20];
int n = 4, m, cnt, ans[15];
inline bool valid(int x, int y)
{
    return (x > 0 && x <= 4 && y > 0 && y <= m);
}
bool findp(int &x, int &y)
{
    for (int i = 1; i <= 4 ;i ++) {
        for (int j = 1; j <= m; j ++) {
            if (!vis[i][j]) {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}
void dfs(int x, int y)
{
    int tx, ty;
    if (valid(x + 1, y) && !vis[x + 1][y]) {
        vis[x][y] = vis[x + 1][y] = 1;
        if (!findp(tx, ty)) {
            cnt ++;
        } else {
            dfs(tx, ty);
        }
        vis[x][y] = vis[x + 1][y] = 0;
    }
    if (valid(x, y + 1) && !vis[x][y + 1]) {
        vis[x][y] = vis[x][y + 1] = 1;
        if (!findp(tx, ty)) {
            cnt ++;
        } else {
            dfs(tx, ty);
        }
        vis[x][y] = vis[x][y + 1] = 0;
    }
}

int main()
{
    for (int i = 1; i <= 10; i ++) {
        memset(vis, 0 ,sizeof vis);
        m = i;
        cnt = 0;
        dfs(1, 1);
        ans[i] = cnt;
        printf("%d ", cnt);
    }
    for (int i = -10; i <= 10; i ++) {
        for (int j = -10; j <= 10; j ++) {
            for (int ii = -10; ii <= 10; ii ++) {
                for (int jj = -10; jj <= 10; jj ++) {
                    for (int k = -10; k <= 10; k ++) {
                        int flag = 1;
                        for (int t = 5; t <= 10; t ++) {
                            if (ans[t] != i * ans[t - 1] + j * ans[t - 2] + ii * ans[t - 3] + jj * ans[t - 4] + k) {
                                flag = 0;
                                break;
                            }
                        }
                        if (flag) {
                            printf("%d %d %d %d %d\n", i, j, ii, jj ,k);
                        }
                    }
                }
            }
        }
    }


}
// 1 5 11 36 95 281 781 2245 6336 18061
