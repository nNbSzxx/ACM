#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 510;
const int INF = 0x3f3f3f3f;
int n, m ,k;
string s[MAX];
int step[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1};

inline bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int bfs (int x, int y, int mode)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    bool vis[MAX][MAX];
    int dis[MAX][MAX];
    memset(vis, 0 ,sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    vis[x][y] = true;
    dis[x][y] = 0;
    while (!q.empty()) {
        pair<int, int> pr = q.front(); q.pop();
        for (int i = 0; i < 4; i ++) {
            int xx = pr.first + step[i][0];
            int yy = pr.second + step[i][1];
            if (mode == 0) {
                if (isValid(xx, yy) && !vis[xx][yy] && s[xx][yy] == '.') {
                    dis[xx][yy] = dis[pr.first][pr.second] + 1;
                    q.push(make_pair(xx, yy));
                    vis[xx][yy] = true;
                    if (xx == n - 1 && yy == m - 1) {
                        return dis[xx][yy];
                    }
                }
            } else {
                if (isValid(xx, yy) && !vis[xx][yy] && s[xx][yy] != 'x') {
                    dis[xx][yy] = dis[pr.first][pr.second] + 1;
                    q.push(make_pair(xx, yy));
                    vis[xx][yy] = true;
                    if (xx == n - 1 && yy == m - 1) {
                        return dis[xx][yy];
                    }
                }
            }
        }
    }
    return INF;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i ++) {
        cin >> s[i];
    }
    int x, y;
    for (int i = 1; i <= k; i ++) {
        cin >> x >> y;
        if (s[x][y] == 'x')
            s[x][y] = 'z';
    }
    int dis0 = bfs(0, 0, 0);
    int dis1 = bfs(0, 0, 1);
    if (dis1 + 5 < dis0) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}

