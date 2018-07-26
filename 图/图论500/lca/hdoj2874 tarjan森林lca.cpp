// MLE fuck!
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e4 + 1;

//int n, m, c;
//struct edge {
//	short v, w, nt;
//} e[20001];
//struct Query {
//	short v;
//	int nt;	
//} query[2000001];
//int cnte, cntq;
//int dis[10001];
//int father[10001], head[10001];
//int headq[10001];
//char vis[10001];
//int ans[1000001];
int n, m, c;
struct edge {
    int v, w, nt;
} e[20001];
int queryv[2000001];
int querynt[2000001];
int cnte, cntq, head[10001], headq[10001];
bool vis[10001];
int father[10001], dis[10001], ans[1000001];

void init(int l)
{
	cnte = cntq = 0;
	memset(head, 0, sizeof head);
	memset(headq, 0, sizeof headq);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= l; i ++) {
		father[i] = i;
	}
}

void add(int u, int v, int w)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].w = w;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

void addq(int u, int v)
{
	++ cntq;
//	printf("addq cntq, u, v: %d %d %d\n", cntq, u, v);
	queryv[cntq] = v;
	querynt[cntq] = headq[u];
	headq[u] = cntq;
}

int find(int x)
{
	return x == father[x] ? father[x] : father[x] = find(father[x]);
}

void merge(int x, int y)
{
//	x = find(x);
//	y = find(y);
	father[y] = x;
}

void tarjan(short u)
{
	int i;
//	printf("u: %d\n", u);
	for (i = head[u]; i; i = e[i].nt) {
		if (!vis[e[i].v]) {
//			printf("u, v: %d %d\n", u, v);
			dis[e[i].v] = dis[u] + e[i].w;
			tarjan(e[i].v);
			merge(u, e[i].v);
		}
	}
	for (i = headq[u]; i; i = querynt[i]) {
//		printf("u, v, id: %d %d %d\n", u, v, id);
		if (vis[queryv[i]]) {
			if (dis[queryv[i]] != -1)
				ans[(i + 1) >> 1] = dis[u] + dis[queryv[i]] - dis[find(queryv[i])] * 2;
			else 
				ans[(i + 1) >> 1] = -1;
		} 
	}
	vis[u] = 1;
}

int main()
{
	int i, u, v, w;
	while (~scanf("%d%d%d", &n, &m, &c)) {
		init(n);
		for (i = 1; i <= m; i ++) {
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		for (i = 1; i <= c; i ++) {
			scanf("%d%d", &u, &v);
			addq(u, v);
			addq(v, u);
		}
		for (i = 1; i <= n; i ++) {
			if (!vis[i]) {
				memset(dis, -1, sizeof dis);
				dis[i] = 0;
				tarjan(i);
			}
		}
		for (i = 1; i <= c; i ++) {
			if (ans[i] != -1) {
				printf("%d\n", ans[i]);
			} else {
				puts("Not connected");
			}
		}
	}
	return 0;
}
