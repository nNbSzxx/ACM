#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;
int a[MAX][MAX], ans;
int step[4][2] =
{-1, -1,
 -1,  0,
  1,  0,
  1,  1};

inline bool isvalid(int x, int y)
{
    return (x >= 0 && x < 6 && y >= 0 && y <= x);
}

void dfs(int dep, int x, int y, int dis, int last)
{
    if (dis == 0) {
        ans = min(ans, dep);
        return ;
    }
    //if (x + dis >= ans) return ;
    if (x + dep >= ans) return ;
    if (dep + dis >= ans) return ;
    for (int i = 0; i < 4; i ++) {
        if (i == 3 - last) continue;
        int xx = x + step[i][0], yy = y + step[i][1], tdis = dis;
        if (!isvalid(xx, yy)) continue;
        if (a[xx][yy] == x) -- tdis;
        if (a[xx][yy] == xx) ++ tdis;
        swap(a[xx][yy], a[x][y]);
        dfs(dep + 1, xx, yy, tdis, i);
        swap(a[xx][yy], a[x][y]);
    }
    return ;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int x, y, dis = 0;
        for (int i = 0; i < 6; i ++) {
            for (int j = 0; j <= i; j ++) {
                scanf("%d", &a[i][j]);
                if (a[i][j] == 0) {
                    x = i;
                    y = j;
                } else if (a[i][j] != i) {
                    ++ dis;
                }
            }
        }
        ans = 21;
        dfs(0, x, y, dis, 4);
        if (ans == 21) {
            puts("too difficult");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
