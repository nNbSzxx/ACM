#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 510;
const int INF = 0x3f3f3f3f;
char mp[MAX][MAX];
int n, m, k;
int dis[MAX][MAX];
int vis[MAX][MAX];
queue<pair<int, int> > q;
int d[4][2] = {
    1, 0,
    -1, 0,
    0, 1,
    0, -1,
};

bool check(int x, int y, char p)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && (mp[x][y] == '.' || mp[x][y] == p) && !vis[x][y];
}


int bfs(int x, int y, char p)
{
    if (x == n && y == m) {
        return 0;
    }
    while (!q.empty()) {
        q.pop();
    }
    q.push(make_pair(x, y));
    dis[x][y] = 0;
    while (!q.empty()) {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int xx = nowx + d[i][0];
            int yy = nowy + d[i][1];
            if (check(xx, yy, p)) {
                vis[xx][yy] = 1;
                dis[xx][yy] = dis[nowx][nowy] + 1;
                if (xx == n && yy == m) {
                    return dis[xx][yy];
                }
                q.push(make_pair(xx, yy));
            }
        }
    }
    return dis[n][m];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) {
        scanf(" %s", (mp[i] + 1));
    }
    for (int i = 1; i <= k; i ++) {
        int u, v;
        scanf("%d %d", &u, &v);
        mp[u + 1][v + 1] = 's';
    }
    dis[n][m] = INF;
    memset(vis, 0, sizeof vis);
    int time1 = bfs(1, 1, 's');
    dis[n][m] = INF;
    memset(vis, 0, sizeof vis);
    int time2 = bfs(1, 1, '.');
    if (time1 + 5 < time2) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
