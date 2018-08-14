#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;
int n, m;

struct edge {
	int v, nt;
} e[MAX << 1];
int head[MAX], cnte, deg[MAX], vis[MAX];
int ans;
bool legal;

void init()
{
	memset(head, 0, sizeof head);
	memset(deg, 0, sizeof deg);
	memset(vis, 0, sizeof vis);
	cnte = ans = 0;
}

void add(int u, int v)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

void dfs(int x, int fa, int r)
{
//	printf("%d\n", x);
	vis[x] = 1;
	if (deg[x] >= 3 || deg[x] <= 1) {
		legal = false;
	}
	for (int i = head[x]; i; i = e[i].nt) {
//		printf("i : %d ", i);
		int v = e[i].v;
		if (!vis[v]) {
			dfs(v, x, r);
		} else {
			if (v == fa) {
				continue;
			} else if (v != r) {
				legal = false;
			} else {
				if (legal) {
					++ ans;
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
		++ deg[u];
		++ deg[v];
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			legal = true;
			dfs(i, -1, i);
//			puts("");
//			printf("%d\n", ans);	
		}
	}
	printf("%d\n", ans);
	return 0;
}
