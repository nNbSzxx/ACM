#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n;
const int MAX = 55;
char s[MAX][MAX];
int step[6][2] = {1, 0, -1, 0, 0, 1, 0, -1, -1, 1, 1, -1};
int bfsvis[MAX][MAX];
int dfsvis[MAX][MAX];
int vis[MAX][MAX];
int color[MAX][MAX];
int ans[MAX * MAX];
int maxx;


inline bool valid(int x, int y)
{
    return (x > 0 && x <= n && y > 0 && y <= n && s[x][y] == 'X');
}

int bfs(int a, int b)
{
    memset(bfsvis, 0 ,sizeof(bfsvis));
    memset(color, 0, sizeof(color));
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    bfsvis[a][b] = 1;
    color[a][b] = 1;
    int hasf[5];
    int ret = 1;
    while (!q.empty()) {
        pair<int, int> now = q.front(); q.pop();
        int x = now.first;
        int y = now.second;
        memset(hasf, 0, sizeof(hasf));
        for (int i = 0; i < 6; i ++) {
            int xx = x + step[i][0];
            int yy = y + step[i][1];
            if (valid(xx, yy)) {
                if (!bfsvis[xx][yy]) {
                    q.push(make_pair(xx, yy));
                    bfsvis[xx][yy] = bfsvis[x][y] + 1;
                } else if (bfsvis[x][y] == bfsvis[xx][yy] || bfsvis[x][y] > bfsvis[xx][yy]) {
                    hasf[color[xx][yy]] = 1;
                }
            }
        }
        for (int j = 1; j <= 3; j ++) {
            if (!hasf[j]) {
            	color[x][y] = j;
                ret = max(ret, j);
                break;
            }
        }
    }
    return ret;
}

void dfs(int x, int y, int block)
{
    for (int i = 0; i < 6; i ++) {
        int xx = x + step[i][0];
        int yy = y + step[i][1];
        if (valid(xx, yy) && !dfsvis[xx][yy]) {
            dfsvis[xx][yy] = block;
            dfs(xx, yy, block);
        }
    }
    return ;
}

/*
int dfslv(int x, int y)
{
    int xx, yy;
    int hasf[5];
    memset(hasf, 0, sizeof(hasf));
    for (int i = 0; i < 6; i ++) {
        xx = x + step[i][0];
        yy = y + step[i][1];
        if (valid(xx, yy)) {
            if (!vis[xx][yy]) {
                vis[xx][yy] = 1;
                dfslv(xx, yy);
            }

            if (bfsvis[xx][yy] == bfsvis[x][y] || bfsvis[xx][yy] > bfsvis[xx][yy]) {
                hasf[bfsvis[x][y]] = 1;
            }
        }
    }
}
*/

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            scanf(" %c", &s[i][j]);
        }
    }
    int cnt = 1;
    memset(dfsvis, 0 ,sizeof(dfsvis));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (s[i][j] == 'X' && !dfsvis[i][j]) {
                dfsvis[i][j] = cnt;
                dfs(i, j, cnt);
                cnt ++;
            }
        }
    }
    -- cnt;
    if (cnt == 0) {
        puts("0");
        return 0;
    }
    //cout << cnt << endl;
    memset(ans , 0x3f, sizeof(ans));
//    memset(color, 0, sizeof(color));
	int sum = -1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (s[i][j] == 'X') {
                ans[dfsvis[i][j]] = min(bfs(i, j), ans[dfsvis[i][j]]);
            }
        }
    }
    for (int i = 1; i <= cnt; i ++) {
        sum = max(sum, ans[i]);
    }
    printf("%d\n", sum);
    return 0;
}
