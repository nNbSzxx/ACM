#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 50010;
const int MAXH = 18;
struct edge {
	int v, w, nt;
} e[MAX << 1];
int head[MAX], dep[MAX], dis[MAX], anc[MAX][MAXH];
int cnte, n, qy;
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
				q.push(v);
				for (int i = 1; i < MAXH; i ++) {
					anc[v][i] = anc[anc[v][i - 1]][i - 1];
				}
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
	int firstin = 1;
	while (~scanf("%d", &n)) {
		if (!firstin) {
			puts("");
		}
		firstin = 0;
		init();
		for (int i = 1; i < n; i ++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u + 1, v + 1, w);
			add(v + 1, u + 1, w);
		}
		bfs(1);
		scanf("%d", &qy);
		while (qy --) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			++ x; ++ y; ++ z;
			int ans = 0;
			ans += dis[x] + dis[y] - 2 * dis[lca(x, y)]; 
			ans += dis[x] + dis[z] - 2 * dis[lca(x, z)]; 
			ans += dis[y] + dis[z] - 2 * dis[lca(y, z)];
			ans /= 2;
			printf("%d\n", ans);
		}
	}
	return 0;
}
