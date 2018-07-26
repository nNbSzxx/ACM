#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010;
const int INF = 0x3f3f3f3f;
char mp[MAX][MAX];
int dis[MAX][MAX], vis[MAX][MAX];
int n, m, k, x1, x2, y1, y2;
int step[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1,
};

inline bool valid(int x, int y)
{
	return (x > 0 && y > 0 && x <= n && y <= m && mp[x][y] == '.');
}

void bfs()
{
	queue<pair<int, int> > q;
	q.push(make_pair(x2, y2));
	memset(dis, 0x3f, sizeof dis);
	dis[x2][y2] = 0;
	vis[x2][y2] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4 ;i ++) {
			for (int j = 1; j <= k; j ++) {
				int xx = x + j * step[i][0];
				int yy = y + j * step[i][1];
				if (!valid(xx, yy)) break;
				if (!vis[xx][yy]) {
					q.push(make_pair(xx, yy));
					vis[xx][yy] = 1;
					dis[xx][yy] = dis[x][y] + 1;
				}
				if (xx == x1 && yy == y1) return;
			}
		}
	}
	return ;
}

int main()
{
	scanf("%d%d%d", &n ,&m , &k);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			scanf(" %c", &mp[i][j]);
		}
	}
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	bfs();
	if (dis[x1][y1] != INF)
		printf("%d\n", dis[x1][y1]);
	else 
		puts("-1");
}
