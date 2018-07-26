#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 1e3 + 10;
const int MAXM = 1e4 + 10;
struct edge {
	int v, w, nt;
} e[MAXM << 1], etp[MAXM << 1];
int head[MAXN], cnte, vis[MAXN], dis[MAXN];
int n, m, k;
queue<int> q;

void init()
{
	cnte = 0;
	memset(head, 0, sizeof head);
}

void add(int u, int v, int w)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].w = w;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

bool spfa(int u)
{
	while (!q.empty()) {
		q.pop();
	}
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	q.push(u);
	dis[u] = 0;
	vis[u] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop(); vis[now] = 0;
		for (int i = head[now]; i; i = etp[i].nt) {
			int v = etp[i].v;
			if (dis[v] > dis[now] + etp[i].w) {
				dis[v] = dis[now] + etp[i].w;
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	return dis[n] <= k;
}

bool check(int mid)
{
	memcpy(etp, e, sizeof e);
	for (int i = 1; i <= cnte; i ++) {
		if (etp[i].w <= mid) {
			etp[i].w = 0;
		} else {
			etp[i].w = 1;
		}
	}
	return spfa(1);
}

int bins()
{
	int l = 0, r = 1e6 + 1, ret = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ret = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ret;
}

int main()
{
	while (~scanf("%d%d%d", &n, &m, &k)) {
		for (int i = 1; i <= m; i ++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		int ans = bins();
		printf("%d\n", ans);
	}
	
	return 0;
} 
