// tarjan lca模板 
/**
* 核心思想：如果要求u，v的lca，有一个点a，
* uv分别在a的左右子树，那么a就是uv的lca
* 用到了并查集 
*/ 
#include <bits/stdc++.h>
using namespace std;
const int MAX = 4e4 + 10;
struct edge {
	int v, w, nt;
} e[MAX << 1];
// 离线算法，需要存储所有查询 
struct Query {
	int id, v;
	Query(int vv, int idd): id(idd), v(vv) {}
};
int head[MAX], father[MAX], vis[MAX];
// 用来存储询问的节点和答案 
int lca[MAX], ulca[MAX], vlca[MAX];
long long dis[MAX]; 
int cnte, n, m;
// 存储所有询问 
vector<Query> query[MAX];

void init()
{
	cnte = 0;
	memset(head, 0, sizeof head);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i ++) {
		father[i] = i;
	}
}

int find(int x)
{
	while (x != father[x]) {
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}

// 并查集合并，注意tarjan求lca的时候，需要把孩子节点 
// 并到父亲节点上，因此合并的时候谁并到谁的次序不能错！
// 把y并到x 
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	father[y] = x;
}

void add(int u, int v, int w)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].w = w;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

// 核心部分 
void tarjan(int u, int fa)
{
	// dfs 
	for (int i = head[u]; i; i = e[i].nt) {
		int v = e[i].v;
		if (v != fa) {
			dis[v] = dis[u] + e[i].w;
			tarjan(v, u);
		}
	}
	// 可以把这些查询看作图的深度优先搜索树上的非树边 
	for (int i = 0; i < query[u].size(); i ++) {
		int v = query[u][i].v;
		int id = query[u][i].id;
		// 如果v被访问过了，这条边如果相当于前向边（祖先指向孩子）
		// 此时find(v) = u 
		// 或者如果是交叉边（无祖先关系）
		// 此时find(v)是使uv在其不同子树的节点 
		if (vis[v]) {
			lca[id] = find(v);
		}
	}
	// 当该节点及其子树所有节点都访问过，才把当前节点并到父节点上 
	// 并且这时才置访问标记
	if (fa != -1)
		merge(fa, u);
	// 第一次访问到该节点就置访问标记也对，
	// 不过会使uv有直接祖先关系的查询查询两次 
	vis[u] = 1; 
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &m);
		init();
		for (int i = 1; i < n; i ++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		for (int i = 1; i <= m; i ++) {
			int u, v;
			scanf("%d%d", &u, &v);
			ulca[i] = u;
			vlca[i] = v;
			query[u].push_back(Query(v, i));
			query[v].push_back(Query(u, i));
		}
		dis[1] = 0;
		tarjan(1, -1);
		for (int i = 1; i <= m; i ++) {
			printf("%lld\n", dis[ulca[i]] + dis[vlca[i]] - 2 * dis[lca[i]]);
		}
	}
	return 0;
}
