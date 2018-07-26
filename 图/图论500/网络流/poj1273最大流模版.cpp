#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 210;
int map[MAX][MAX];
int layer[MAX], n , m;

bool countLayer (void)
{
	int vis[MAX];
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	layer[1] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 1; i <= n; i ++) {
			if (map[now][i] > 0 && !vis[i]) {
				layer[i] = layer[now] + 1;
				vis[i] = 1;
				q.push(i);
				if (i == n) {
					return true;
				} 
			}
		}
	}
	return false;
}
int dinic(void)
{
	int flow = 0, vis[MAX];
	deque<int> q;
	while (countLayer()) {
		q.push_back(1);
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		while (!q.empty()) {
			int now = q.back();
			if (now == n) {
				int minn = INF;
				int minid;
				for (int i = 1; i < q.size(); i ++) {
					int vs = q[i - 1];
					int ve = q[i];
					if (map[vs][ve] > 0 && minn > map[vs][ve]) {
						minn = map[vs][ve];
						minid = vs;
					}
				}
				flow += minn;
				for (int i = 1; i < q.size(); i ++) {
					int vs = q[i - 1];
					int ve = q[i];
					map[vs][ve] -= minn;
					map[ve][vs] += minn;
				}
				while (!q.empty() && q.back() != minid) {
					vis[q.back()] = 0;
					q.pop_back();
				}
			} else {
				int i;
				for (i = 1; i <= n; i ++) {
					if (map[now][i] > 0 && !vis[i] && layer[now] + 1 == layer[i]) {
						q.push_back(i);
						vis[i] = 1;
						break;
					}
				}
				if (i > n) {
					q.pop_back();
				}
			}
		}
	}
	return flow;
}

int main()
{
	while (~scanf("%d%d", &m, &n) ) {
		int u, v, w;
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d", &u, &v, &w);
			map[u][v] += w;
		}
		
		printf("%d\n", dinic());
	}
	return 0;
}
