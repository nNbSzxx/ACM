#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20010;
const int MAXM = 50010;
struct edge {
	int v, nt;
} e[MAXM];
int cnte, n, m, head[MAXN], dfn[MAXN], low[MAXN], color[MAXN], cntc, idx;
int indegree[MAXN], outdegree[MAXN];
stack<int> s;

void init()
{
	cnte = 0;
	cntc = 0;
	idx = 0;
	memset(head, 0, sizeof head);
	memset(dfn, 0, sizeof dfn);
	memset(color, 0, sizeof color);
	memset(indegree, 0, sizeof indegree);
	memset(outdegree, 0, sizeof outdegree);
}

void add(int u, int v)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++ idx;
	s.push(u);
	for (int i = head[u]; i; i = e[i].nt) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (!color[v]){
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		++ cntc;
		while (true) {
			int now = s.top(); s.pop();
			color[now] = cntc;
			if (now == u) {
				break;
			}
		}
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		init();
		scanf("%d%d", &n, &m);
		int u, v;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d", &u, &v);
			add(u, v);
		}
		for (int i = 1; i <= n; i ++) {
			if (!dfn[i])
				tarjan(i);
		}
		for (int u = 1; u <= n; u ++) {
			for (int i = head[u]; i; i = e[i].nt) {
				if (color[u] != color[e[i].v]) {
					++ outdegree[color[u]];
					++ indegree[color[e[i].v]];
				}
			}
		}
		int in0 = 0, out0 = 0;
		for (int i = 1; i <= cntc; i ++) {
			if (indegree[i] == 0) {
				++ in0;
			}
			if (outdegree[i] == 0) {
				++ out0;
			}
		}
		if (cntc != 1)
			printf("%d\n", max(in0, out0));
		else
			puts("0");
	}
	return 0;
}
