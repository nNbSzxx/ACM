// 倍增求LCA 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1e4 + 10;
// 最大深度对二取对数 
const int MAXH = 17;
queue<int> q;
struct edge {
	int v, w, nt;
} e[MAX << 1];
int n, head[MAX], cnte, dep[MAX], m, c;
int dis[MAX], vis[MAX];
// anc[i][j]表示第i个节点向上跳2^j层后的节点
// anc[i][0]就是父亲节点
// 如果跳2^j层后超过了root，那么anc[i][j] = root
int anc[MAX][MAXH]; 

void init()
{
	cnte = 0;
	memset(head, 0, sizeof head);
	memset(vis, 0, sizeof vis);
}

void add(int u, int v, int w)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].w = w;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

// x向上跳h层后的节点编号 
int swim(int x, int h)
{
	int ret = x;
	// 从二进制角度看，如6=110，那么先跳2层，再跳4层
	for (int i = 0; h; i ++, h >>= 1) {
		if (h & 1) {
			ret = anc[ret][i];
		}
	}
	return ret;
}

// 遍历整个树，打出anc表
void bfs(int root, int color)
{
	vis[root] = color;
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
				vis[v] = color;
				dep[v] = dep[u] + 1;
				dis[v] = dis[u] + e[i].w;
				anc[v][0] = u;
				for (int i = 1; i < MAXH; i ++) {
					// 倍增 
					anc[v][i] = anc[anc[v][i - 1]][i - 1];
				}
				q.push(v);
			}
		}
	}
}

int lca(int x, int y)
{
	if (vis[x] != vis[y]) return -1;
	if (dep[x] < dep[y]) {
		swap(x, y);
	}
	// 先把较深的跳到较浅的同一高度 
	x = swim(x, dep[x] - dep[y]);
	if (x == y) {
		return x;
	}
	// 后一次跳的高度一定比前一次跳的高度还小
	// 可以用反证法证明
	for (int i = MAXH - 1; i >= 0; i --) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	// 循环结束后，anc[x][0] = anc[y][0] = lca 
	return anc[x][0];
}

int main()
{
	while (~scanf("%d%d%d", &n, &m, &c)) {
		init();
		int u, v, w;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (!vis[i]) {
				++ cnt;
				bfs(i, cnt);
			}
		}
		while (c --) {
			scanf("%d%d", &u, &v);
			int lc = lca(u, v);
			if (lc == -1)
				puts("Not connected");
			else 
				printf("%d\n", dis[u] - 2 * dis[lc] + dis[v]);
		
		}
	}
	return 0;
}




