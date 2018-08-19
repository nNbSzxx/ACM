#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1e6 + 10;

struct edge {
	int v, nt;
} e[MAX << 2];

int head[MAX], cnt = 0;
int a[MAX], b[MAX];
int occ[MAX], zhan[MAX], vis[MAX];
int ans = 0;
int solve[MAX];
queue<int> q;

void add(int u, int v)
{
	++ cnt;
	e[cnt].v = v;
	e[cnt].nt = head[u];
	head[u] = cnt;	
} 

int bfs(int x, int md)
{
	int maxx = 1e9 + 10;
	q.push(x);
	vis[x] = 1;
	if (md == 0) {
		zhan[a[x]] = 1;
		maxx = a[x];	
	} else {
		zhan[b[x]] = 1;
		maxx = b[x];
	}
	
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = head[now]; i; i = e[i].nt) {
			int v = e[i].v;
			
			if (!vis[v]) {
				if (!zhan[a[v]]) {
					zhan[a[v]] = 1;
					maxx = max(a[v], maxx);
				} else if (!zhan[b[v]]) {
					zhan[b[v]] = 1;
					maxx = max(b[v], maxx);
				} else {
					return 1e9 + 10;
				}
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	return maxx;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n ; i ++) {
		solve[i] = 1e9 + 10;
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &a[i], &b[i]);
		if (occ[a[i]]) {
			add(occ[a[i]], i);
			add(i, occ[a[i]]);
		} else {
			occ[a[i]] = i;
		}
		if (occ[b[i]]) {
			add(occ[b[i]], i);
			add(i, occ[b[i]]);
		} else {
			occ[b[i]] = i;
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			solve[i] = bfs(i, 0);
		}
	}
	memset(zhan, 0, sizeof zhan);
	memset(vis, 0, sizeof vis);
	bool ok = true;
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			solve[i] = min(bfs(i, 1), solve[i]);
			if (solve[i] == 1e9 + 10) {
				ok = false;
				break;
			} else {
				ans = max(ans, solve[i]);
			}
		}
	}
	if (ok && ans <= 1e9 + 10) {
		printf("%d\n", ans);
	} else {
		puts("-1");
	}
	return 0;
}
