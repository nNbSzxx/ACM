#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010;
int sg[MAX][MAX];

int dfssg(int x, int y)
{
    if (sg[x][y] != -1) return sg[x][y];
    int vis[MAX * 100] = {0};
    vis[0] = 1;
    for (int i = 1; i <= x; i ++) {
        for (int j = 1; j <= y; j ++) {
            if (i == x && j == y) continue;
            int now = 0;
            for (int ii = i; ii <= x; ii ++) {
                for (int jj = j; jj <= y; jj ++) {
                    if (ii == x && jj == y) continue;
                    now ^= dfssg(ii, jj);
                }
            }
            vis[now] = 1;
        }
    }
    for (int i = 0; ; i ++) {
        if (!vis[i])
            return sg[x][y] = i;
    }
}

int main()
{
    memset(sg, -1, sizeof sg);
    for (int i = 1; i <= 32; i ++) {
        for (int j = 1; j <= 32; j ++) {
            dfssg(i, j);
            printf("%-4d", sg[i][j]);
        }
        puts("");
    }
}
