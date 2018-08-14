#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 10;
const int INF = 0x3f3f3f3f;
struct edge {
	int v, w, nt;
} e[MAXM];
int n, m, s, t;
int head[MAXN]; 
int cnte, dis[MAXN], vis[MAXN], deg[MAXN], order[MAXN], cur;
int sid, tid;
queue<int> q;

void init()
{
	cnte = cur = 0;
	memset(dis, 0x3f, sizeof dis);
}

void add(int u, int v, int w)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].w = w;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

void tsort()
{
	for (int i = 1; i <= n; i ++) {
		if (!deg[i]) {
			q.push(i);
			order[++ cur] = i;
			if (i == s) {
				sid = cur;
			}
			if (i == t) {
				tid = cur;
			}
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = head[now]; i; i = e[i].nt) {
			int v = e[i].v;
			-- deg[v];
			if (!deg[v]) {
				q.push(v);
				order[++ cur] = v;
				if (v == s) {
					sid = cur;
				}
				if (v == t) {
					tid = cur;
				}
			}
		}
	}
	return ;
}

int main()
{
	init();
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i ++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		++ deg[v];
	}
	tsort();
	if (tid < sid) {
		puts("Unreachable");
		return 0;
	}
	dis[s] = 0;
	for (int i = sid; i <= n; i ++) {
		int now = order[i];
		if (now == t) {
			break;
		}
		if (dis[now] == INF) {
			continue;
		}
		for (int j = head[now]; j; j = e[j].nt) {
			int v = e[j].v;
			dis[v] = min(dis[v], dis[now] + e[j].w);
		}
	}
	if (dis[t] == INF)
		puts("Unreachable");
	else 
		printf("%d\n", dis[t]);
	return 0;
}








