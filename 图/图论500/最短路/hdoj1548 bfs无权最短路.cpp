#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 205;
int k[MAX];
int dis[MAX], vis[MAX];
int n, a, b;
bool ok(int x)
{
	return (x >= 1 && x <= n && !vis[x]);
}
int bfs(int u, int v)
{
	if (u == v) return 0;
	queue<int> q;
	q.push(u);
	vis[u] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		int x = now - k[now];
		if (ok(x)) {
			if (x == v) return dis[now] + 1;
			vis[x] = 1;
			q.push(x);
			dis[x] = dis[now] + 1;
		}
		x = now + k[now];
		if (ok(x)) {
			if (x == v) return dis[now] + 1;
			vis[x] = 1;
			q.push(x);
			dis[x] = dis[now] + 1;
		}
	}
	return -1; 
}
void init(void)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
}
int main()
{
	while (~scanf("%d",&n), n) {
		scanf("%d%d",&a, &b);
		for (int i = 1; i <= n ; i ++) {
			scanf("%d",&k[i]);
		}
		init();
		printf("%d\n",bfs(a, b));
	}
	return 0;
}
