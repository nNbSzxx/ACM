#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n, m, h, cnt, idx, tot;
int mt[MAX], head[MAX], dfn[MAX], low[MAX], vis[MAX], belong[MAX], hasout[MAX];
stack<int> s;
vector<int> vec[MAX];
struct edge {
	int v, nt, u;
} e[MAX * 2];

void add(int u, int v)
{
	e[cnt].v = v;
	e[cnt].u = u;
	e[cnt].nt = head[u];
	head[u] = cnt;
	++ cnt; 
}

void tarjan(int x)
{
//	printf("%d\n\n", x);
	dfn[x] = low[x] = ++ idx;
	vis[x] = 1;
	s.push(x);
	for (int i = head[x]; i; i = e[i].nt) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[x] = min(low[x], low[v]);
		} else if (vis[v]){
			low[x] = min(low[x], dfn[v]);
		}
	}
	if (low[x] == dfn[x]) {
		while(1) {
			int now = s.top();
			vis[now] = 0;
			s.pop();
			belong[now] = tot;
			vec[tot].push_back(now);
			if (x == now)
				break;
		}
		++ tot;
	}
}

int main()
{
	memset(dfn, 0, sizeof dfn);
	memset(head, 0, sizeof head);
	memset(vis, 0, sizeof vis);
	memset(hasout, 0, sizeof hasout);
//	memset(e, 0, sizeof e);
	cnt = 1; idx = 0; tot = 0;
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &mt[i]);
	}
	int u, v;
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d", &u, &v);
		if (mt[v] - mt[u] == 1 || mt[u] - mt[v] == h - 1)
			add(u, v);
		if (mt[u] - mt[v] == 1 || mt[v] - mt[u] == h - 1)
			add(v, u);
	}
	for (int i = 1; i <= n; i ++) {
		if (!dfn[i])
			tarjan(i);
	}
//	printf("%d\n", tot);
	int ans = 0x3f3f3f3f, id = -1;
	for (int i = 1; i < cnt; i ++) {
		if (belong[e[i].u] != belong[e[i].v]) {
			hasout[belong[e[i].u]] = 1;
		}
	}
	for (int i = 0; i < tot; i ++) {
		if (!hasout[belong[vec[i][0]]] && vec[i].size() < ans) {
			id = i;
			ans = vec[i].size();
		}
	}
	printf("%d\n", ans);
	for (int a : vec[id]) {
		printf("%d ", a);
	}
	return 0;
}
