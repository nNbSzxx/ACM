// tarjan lcaģ�� 
/**
* ����˼�룺���Ҫ��u��v��lca����һ����a��
* uv�ֱ���a��������������ôa����uv��lca
* �õ��˲��鼯 
*/ 
#include <bits/stdc++.h>
using namespace std;
const int MAX = 4e4 + 10;
struct edge {
	int v, w, nt;
} e[MAX << 1];
// �����㷨����Ҫ�洢���в�ѯ 
struct Query {
	int id, v;
	Query(int vv, int idd): id(idd), v(vv) {}
};
int head[MAX], father[MAX], vis[MAX];
// �����洢ѯ�ʵĽڵ�ʹ� 
int lca[MAX], ulca[MAX], vlca[MAX];
long long dis[MAX]; 
int cnte, n, m;
// �洢����ѯ�� 
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

// ���鼯�ϲ���ע��tarjan��lca��ʱ����Ҫ�Ѻ��ӽڵ� 
// �������׽ڵ��ϣ���˺ϲ���ʱ��˭����˭�Ĵ����ܴ�
// ��y����x 
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

// ���Ĳ��� 
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
	// ���԰���Щ��ѯ����ͼ����������������ϵķ����� 
	for (int i = 0; i < query[u].size(); i ++) {
		int v = query[u][i].v;
		int id = query[u][i].id;
		// ���v�����ʹ��ˣ�����������൱��ǰ��ߣ�����ָ���ӣ�
		// ��ʱfind(v) = u 
		// ��������ǽ���ߣ������ȹ�ϵ��
		// ��ʱfind(v)��ʹuv���䲻ͬ�����Ľڵ� 
		if (vis[v]) {
			lca[id] = find(v);
		}
	}
	// ���ýڵ㼰���������нڵ㶼���ʹ����Űѵ�ǰ�ڵ㲢�����ڵ��� 
	// ������ʱ���÷��ʱ��
	if (fa != -1)
		merge(fa, u);
	// ��һ�η��ʵ��ýڵ���÷��ʱ��Ҳ�ԣ�
	// ������ʹuv��ֱ�����ȹ�ϵ�Ĳ�ѯ��ѯ���� 
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
