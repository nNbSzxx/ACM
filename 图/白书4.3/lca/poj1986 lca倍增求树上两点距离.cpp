#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 40010;
const int MAXH = 17;
struct edge {
	int v, w, nt;
} e[MAX << 1];
int n, m, k, cnte;
int head[MAX], dep[MAX], anc[MAX][MAXH], dis[MAX];
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
	dis[root] = 0;
	dep[root] = 1;
	q.push(root);
	for (int i = 0; i < MAXH; i ++) {
		anc[root][i] = root;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = e[i].nt) {
			int v = e[i].v;
			if (v != anc[u][0]) {
				anc[v][0] = u;
				dep[v] = dep[u] + 1;
				dis[v] = dis[u] + e[i].w;
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
	if (x == y) {
		return x;
	}
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
	while (~scanf("%d%d", &n, &m)) {
		init();
		for (int i = 1; i <= m; i ++) {
			int u, v, w;
			scanf("%d%d%d %*c", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		bfs(1);
		int k;
		scanf("%d", &k);
		while (k --) {
			int u, v;
			scanf("%d%d", &u, &v);
			int lc = lca(u, v);
			printf("%d\n", dis[u] - 2 * dis[lc] + dis[v]);
		}
	}
	return 0;
}




