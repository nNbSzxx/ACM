#include <bits/stdc++.h>
using namespace std;
const int MAXM = 250000 + 10;
const int MAXN = 510;
const int INF = 0x3f3f3f3f;

struct Edge {
	int v, w, nt;
} e[MAXM];
int n, m, s, d;
int res[MAXN], path[MAXN], head[MAXN], vis[MAXN], dis[MAXN], r[MAXN];
int cnt = 1, ans, rans;
vector<int> anspath;

class Node {
	public: 
		int v, len;
		Node(int vv, int lenn) : v(vv), len(lenn) {}
		bool operator< (const Node& rhs) const {
			return len > rhs.len;
		}
};

void add(int u, int v, int w)
{
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].nt = head[u];
	head[u] = cnt ++;
}

void dij()
{
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	priority_queue<Node, vector<Node> > q;
	q.push(Node(s, 0));
	while (!q.empty()) {
		Node now = q.top(); q.pop();
		int u = now.v;
		if (u == d) return ;
		if (vis[u]) continue;
		vis[u] = true;
		
		for (int i = head[u]; i; i = e[i].nt) {
			int v = e[i].v, w = e[i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(Node(v, dis[v]));
			} 
		}
	}
}

void dfs(int x, int r)
{
	if (x == d) {
		if (r > rans) {
			rans = r;
			while (!anspath.empty()) {
				anspath.pop_back();
			}
			for (int i = s; i != d; i = path[i]) {
				anspath.push_back(i);
			}
		}
//		printf("path: ");
//		for (int i = s; i != d; i = path[i]) {
//			printf("%d ", i);
//		}
//		puts("");
		++ ans;
		return ;
	}
	
	for (int i = head[x]; i; i = e[i].nt) {
		int v = e[i].v;
		if (dis[v] == dis[x] + e[i].w) {
			path[x] = v;
			dfs(v, r + res[v]);
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m ,&s, &d);
	++ s; ++ d;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &res[i]);
	}
	for (int i = 1; i <= m; i ++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u + 1, v + 1, w);
		add(v + 1, u + 1, w);
	}
	dij();
	ans = 0; rans = -1;
	dfs(s, res[s]);
	printf("%d %d\n", ans, rans);
	for (int i = 0; i < anspath.size(); i ++) {
		printf("%d ", anspath[i] - 1);
	}
	printf("%d\n", d - 1);
//	for (int i = s; i != d; i = path[i]) {
//		printf("%d ", i - 1);
//	}
//	printf("%d\n", d - 1);
	return 0;
}

/*
void spfa()
{
	ans = 0;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	queue<int> q;
	dis[s] = 0;
	r[s] = res[s];
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop(); vis[now] = 0;
		for (int i = head[now]; i; i = e[i].nt) {
			int v = e[i].v, w = e[i].w;
			if (dis[v] > dis[now] + w) {
				dis[v] = dis[now] + w;
				r[v] = r[now] + res[v];
				path[now] = v;
				if (v == d) {
					ans = 1;
				}
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			} else if (dis[v] == dis[now] + w && r[v] <= r[now] + res[v]) {
				r[v] = r[now] + res[v];
				path[now] = v;
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
				if (v == d) {
					ans ++;
				}
			}
		}
	}
}
*/
