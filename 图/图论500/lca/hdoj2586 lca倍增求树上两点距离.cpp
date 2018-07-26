#include <bits/stdc++.h>
using namespace std;
const int MAX = 4e4 + 10;
const int MAXH = 17;
struct edge {
	int v, w, nt;
} e[MAX << 1];
int head[MAX], dep[MAX], anc[MAX][MAXH];
int n, m, cnte;
long long dis[MAX];
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

void bfs(int root)
{
	dep[root] = 1;
	dis[root] = 0;
	q.push(root);
	for (int i = 0; i < MAXH; i ++) {
		anc[root][i] = root;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = e[i].nt) {
			int v = e[i].v;
			if (v != anc[u][0]) {
				dep[v] = dep[u] + 1;
				dis[v] = dis[u] + e[i].w;
				anc[v][0] = u;
				for (int i = 1; i < MAXH; i ++) {
					anc[v][i] = anc[anc[v][i - 1]][i - 1];
				}
				q.push(v);
			}
		}
	}
}

int swim(int x, int h)
{
	int ret = x;
	for (int i = 0; h; i ++, h >>= 1) {
		if (h & 1) {
			ret = anc[ret][i];
		}
	}	
	return ret;
} 

int lca(int x, int y)
{
	if (dep[x] < dep[y]) {
		swap(x, y);
	}
	x = swim(x, dep[x] - dep[y]);
	if (x == y) return x;
	for (int i = MAXH - 1; i >= 0; i --) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		init();
		scanf("%d%d", &n, &m);
		for (int i = 1; i < n; i ++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		bfs(1);
		while (m --) {
			int u, v;
			scanf("%d%d", &u, &v);
			int lc = lca(u, v);
			printf("%lld\n", dis[u] + dis[v] - 2 * dis[lc]);
		}
	}
	return 0;
}
