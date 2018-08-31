#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 200;
int sg[MAX + 5][MAX + 5];

int dfs(int x, int y)
{
	if (x > y) {
		swap(x, y);
	}
//	printf("%d %d\n", x, y);
	if (sg[x][y] != -1) {
//		printf("%d %d %d\n", x, y, sg[x][y]);
		return sg[x][y];
	}
	int vis[MAX + MAX + 3];
	memset(vis, 0, sizeof vis);
	for (int i = 2; i < x - 1; i ++) {
		vis[dfs(x - i, y) ^ dfs(i, y)] = 1;
	}
	for (int i = 2; i < y - 1; i ++) {
		vis[dfs(x, y - i) ^ dfs(x, i)] = 1;
	}
	for (int i = 0; ; i ++) {
		if (!vis[i]) {
//			printf("%d %d %d\n", x, y, i);
			return sg[x][y] = i;
		}
	}
}

int main()
{
	int w, h;
	memset(sg, -1, sizeof sg);
	sg[2][2] = 0;
	while (~scanf("%d%d", &w, &h)) {
		if (dfs(w, h)) {
			puts("WIN");
		} else {
			puts("LOSE");
		}
//		printf("%d\n", sg[min(w, h)][max(w, h)]);
	}
	return 0;
}
