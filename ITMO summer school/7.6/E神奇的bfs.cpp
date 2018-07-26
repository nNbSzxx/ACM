#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;
int n, k;
int dis[2 * MAX];
vector<int> v;

int bfs(void)
{
	int vis[2 * MAX];
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(1005);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < v.size(); i ++) {
			int x = now + v[i];
			if (x >= 0 && x <= 2010 && !vis[x]) {
				vis[x] = 1;
				q.push(x);
				if (now != 1005) dis[x] = dis[now] + 1;
				if (x == 1005) return dis[x];
			}
		}
	}
	return INF;
}
int main()
{
	int x;
	memset(dis, 0x3f, sizeof(dis));
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i ++) {
		scanf("%d", &x);
		dis[x + 1005 - n] = 1;
	}
	for (int i = 0; i <= 2000; i ++) {
		if (dis[i] == 1) {
			v.push_back(i - 1005);
		}
	}
	int ret = bfs();
	if (ret == INF)
		printf("-1\n");
	else
		printf("%d\n", ret);
	return 0;
}

