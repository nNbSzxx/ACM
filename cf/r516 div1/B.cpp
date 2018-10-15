#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 2010;
int n, m;
int r, c;
int ll, rr;
char mp[MAX][MAX];
int d[4][2] = {
    -1, 0,
    1, 0,
    0, -1,
    0, 1,
};

struct node {
    int x, y;
    int l, r;
    node (int xx, int yy, int ll, int rr) :
        x(xx), y(yy), l(ll), r(rr) {}
};

queue<node> q;
int ans = 0;

void addCol(int x, int y, queue<node> &qq, int l, int r)
{
    for (int i = x; mp[i][y] != '*'; i ++) {
        if (mp[i][y] == '.') {
            q.push(node(i, y, l, r));
            mp[i][y] = '+';
            ++ ans;
        }
    }
    for (int i = x - 1; mp[i][y] != '*'; i --) {
        if (mp[i][y] == '.') {
            q.push(node(i, y, l, r));
            mp[i][y] = '+';
            ++ ans;
        }
    }
}

void bfs()
{
    addCol(r, c, q, ll, rr);
    while (!q.empty()) {
        node now = q.front(); q.pop();
        if (now.l && mp[now.x][now.y - 1] == '.') {
            addCol(now.x, now.y - 1, q, now.l - 1, now.r);
        }
        if (now.r && mp[now.x][now.y + 1] == '.') {
            addCol(now.x, now.y + 1, q, now.l, now.r - 1);
        }
    }
}

int main()
{
    scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &ll, &rr);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            scanf(" %c", &mp[i][j]);
        }
    }
    for (int i = 0; i <= n + 1; i ++) {
        mp[i][0] = mp[i][m + 1] = '*';
    }
    for (int j = 0; j <= m + 1; j ++) {
        mp[0][j] = mp[n + 1][j] = '*';
    }
    bfs();
    printf("%d\n", ans);
    return 0;
}
