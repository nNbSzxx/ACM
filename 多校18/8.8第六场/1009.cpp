#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 1e5 + 10;
const int V = 0;
const int W = 1;
const int FV = 2;
const int FW = 3;
int cnte, cntef, idx, cntc, ans;
int heade[MAX], headef[MAX], dfn[MAX], color[MAX], low[MAX];
int vis[MAX], tag[MAX];
int cntw, wid;
queue<int> q;
stack<int> s;

struct edge {
	int v, nt, kind;
} e[MAX], ef[MAX];

void init()
{
	cnte = cntef = 1;
	idx = cntc = ans = 0;
	memset(heade, 0, sizeof heade);
	memset(headef, 0, sizeof headef);
	memset(dfn, 0, sizeof dfn);
	memset(color, 0, sizeof color);
	memset(vis, 0, sizeof vis);
	memset(tag, 0, sizeof tag);
	while (!q.empty()) {
		q.pop();
	}
	while (!s.empty()) {
		s.pop();
	}
}

void adde(int u, int v, int kind)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].nt = heade[u];
	e[cnte].kind = kind;
	heade[u] = cnte;
}

void addef(int u, int v, int kind)
{
	++ cntef;
	ef[cntef].v = v;
	ef[cntef].kind = kind;
	ef[cntef].nt = headef[u];
	headef[u] = cntef;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ idx;
    s.push(u);
    for (int i = heade[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!color[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
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

void bfs(int x)
{
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int eid = heade[now];
		int v = e[eid].v;
		if (color[v] == color[now]) {
			if (e[eid].kind == W) {
				++ cntw;
				wid = v;
			}
			if (v != x) {
				q.push(v);
			}
		}
	}
}

void dfs(int x)
{
	++ ans;
	vis[x] = 1;
	for (int i = headef[x]; i; i = ef[i].nt) {
		if (!vis[ef[i].v]) {
			dfs(ef[i].v);
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		init();
		int n;
		scanf("%d", &n);
		int id;
		char s[22];
		for (int i = 1; i <= n ;i ++) {
			scanf("%d %s", &id, s);
			if (!strcmp(s, "werewolf")) {
				adde(i, id, W);
			} else {
				addef(id, i, FV);
				adde(i, id, V);
			}
		}
		for (int i = 1; i <= n; i ++) {
			if (!dfn[i]) {
				tarjan(i);
			}
		}
		for (int i = 1; i <= n; i ++) {
			if (!vis[color[i]]) {
				cntw = 0;
				wid = -1;
				vis[color[i]] = 1;
				bfs(i);
				if (cntw == 1) {
					tag[wid] = 1;
				}
			}
		}
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i ++) {
			if (tag[i]) {
				dfs(i);
			}
		}
		printf("%d %d\n", 0, ans);
	}	
	
	return 0;	
}
