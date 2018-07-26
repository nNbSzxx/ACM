#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 105;
char g[MAX][MAX];
int vis[MAX][MAX], s1, s0, c0, c1;
int issur, n, m;
int step[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

inline int isvalid(int x, int y, int s)
{
	if (x <= 0 || x > n || y <= 0 || y > m) {
		return 0;
	}
	if (g[x][y] == s + '0') {
		return 1;
	} else {
		return -1;
	}
}

void dfs(int x, int y, int s)
{
	for (int i = 0; i < 4; i ++) {
		int xx = x + step[i][0];
		int yy = y + step[i][1];
		int st = isvalid(xx, yy, s);
		if (st == 0) {
			issur = 0;
			continue;
		}
		if (st == -1) continue;
		if (!vis[xx][yy]) {
			vis[xx][yy] = 1;
			dfs(xx, yy, s);
		}
	}
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		s0 = s1 = c0 = c1 = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				scanf(" %c", &g[i][j]);
			}
		}
		
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				if (!vis[i][j]) {
					vis[i][j] = 1;
					issur = 1;
					if (g[i][j] == '0') {
						c0 ++;
						dfs(i, j, 0);
						if (issur) {
							s0 ++;
						}
					} else {
						c1 ++;
						dfs(i, j, 1);
						if (issur) {
							s1 ++;
						}
					}
				}
			}
		}
		if (c1 == 1 && s0 == 1) {
			puts("0");
		} else if (c1 == 1 && s0 == 0) {
			puts("1");
		} else {
			puts("-1");
		}
		
	}
	
	return 0;
}


