#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 1050;
int map[MAX][MAX];
int layer[MAX];
int bottom, n, low, high, m;
int a[MAX];

bool countLayer (void)
{
	int vis[MAX];
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(0);
	vis[0] = 1;
	layer[0] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 1; i <= n + 1; i ++) {
			if (map[now][i] > 0 && !vis[i]) {
				layer[i] = layer[now] + 1;
				vis[i] = 1;
				q.push(i);
				if (i == n + 1) {
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
		q.push_back(0);
		memset(vis, 0, sizeof(vis));
		vis[0] = 1;
		while (!q.empty()) {
			int now = q.back();
			if (now == n + 1) {
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
				for (i = 1; i <= n + 1; i ++) {
					if (map[now][i] > 0 && !vis[i] && layer[now] + 1 == layer[i]) {
						q.push_back(i);
						vis[i] = 1;
						break;
					}
				}
				if (i > n + 1) {
					q.pop_back();
				}
			}
		}
	}
	return flow;
}

int main()
{
    cin >> n >> low >> high >> m;
    memset(map, 0, sizeof(map)); 
//	bottom = INF;
	for (int i = 1; i <= m; i ++) {
        cin >> a[i];
//      bottom = min(bottom, a[i]);
        if (a[i] < low) {
        	map[0][a[i]] = INF;
		} else if (a[i] > high) {
			map[a[i]][n + 1] = INF;
		}
		if (i > 1) {
			map[a[i]][a[i - 1]] += 1;
			map[a[i - 1]][a[i]] += 1;
		}
    }
    cout << dinic() << endl;
    return 0;
}
