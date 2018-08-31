#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 10;
const int INF = 0x3f3f3f3f;

struct edge {
	int v, c, p, r, nt;
} e[(MAX << 1) + 10];
struct node {
	int mask, u;
	node(int maskk, int uu) : mask(maskk), u(uu) {}
};
queue<node> q;
int head[MAX], cnte;
int dp[(1 << MAX) + 10][MAX + 3];
int vis[(1 << MAX) + 10][MAX + 3];
int n, m;

void add(int u, int v, int c, int p, int r)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].c = c;
	e[cnte].p = p;
	e[cnte].r = r;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		memset(head, 0, sizeof head);
		cnte = 0;
		for (int i = 1; i <= m; i ++) {
			int u, v, c, p, r;
			scanf("%d%d%d%d%d", &u, &v, &c, &p, &r);
			-- u;
			-- v;
			-- c;
			add(u, v, c, p, r);
//			add(v, u, c, p, r);
		}
		memset(dp, 0x3f, sizeof dp);
		memset(vis, 0, sizeof vis);
		dp[1][0] = 0;
		while (!q.empty()) q.pop();
		q.push(node(1, 0));
		vis[1][0] = 1;
		while (!q.empty()) {
			int mask = q.front().mask;
			int u = q.front().u;
//			printf("mask u dp : %d %d %d\n", mask, u, dp[mask][u]);
			q.pop();
			vis[mask][u] = 0;
			for (int i = head[u]; i; i = e[i].nt) {
				int v = e[i].v;
				int c = e[i].c;
				int p = e[i].p;
				int r = e[i].r;
				int newmask = mask | (1 << v);
				if (mask & (1 << c)) {
					if (dp[newmask][v] > dp[mask][u] + p) {
						dp[newmask][v] = dp[mask][u] + p;
						if (!vis[newmask][v]) {
							vis[newmask][v] = 1;
							q.push(node(newmask, v));
						}	
					}
				} else {
					if (dp[newmask][v] > dp[mask][u] + r) {
						dp[newmask][v] = dp[mask][u] + r;
						if (!vis[newmask][v]) {
							vis[newmask][v] = 1;
							q.push(node(newmask, v));
						}	
					}
				}
			}
		}
		
		int ans = INF;
		int id;
		for (int mask = 0; mask < (1 << n); ++ mask) {
			if (mask & (1 << (n - 1))) {
				ans = min(ans, dp[mask][n - 1]);
			}
			
		}
		if (ans == INF) {
			puts("impossible");
		} else {
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
