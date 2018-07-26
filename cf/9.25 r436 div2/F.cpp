#include <bits/stdc++.h>
using namespace std;
const int MAXQ = 4e5 + 10;
const int MAX = 3e3 + 10;
int n, m, q, st[16][MAX], vis[MAX], ans[MAXQ];
struct Q {
	int u, v, k, id;
} qq[MAXQ];
vector<int> e[MAX], re[MAX];
queue<int> que;

void bfs(int u)
{
//	cout << 111111 << endl;
	vis[u] = 1;
	que.push(u);
	while (!que.empty()) {
		int now = que.front(); que.pop();
		for (int i = 0; i < re[now].size(); i ++) {
			int v = re[now][i];
			if (!vis[v]) {
				vis[v] = 1;
				que.push(v);
			}
		}
	}
}

int getNt(int u)
{
	int i = 0;
	for (; i < e[u].size(); i ++) {
		if (vis[e[u][i]]) return e[u][i];
	}
	return 0;
}

bool cmp(const Q& q1, const Q& q2) {
	return q1.v < q2.v;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	int u, v;
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		re[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++) {
		sort(e[i].begin(), e[i].end());
	}
	int k;
	for (int i = 1; i <= q; i ++) {
		scanf("%d%d%d", &qq[i].u, &qq[i].v, &qq[i].k);
		qq[i].id = i;
	}
	sort(qq + 1, qq + q + 1, cmp);
//	for (int i = 1; i <= q; i ++) {
//		cout << qq[i].v << " " << qq[i].id << endl;
//	}
	int loc = 1;
	for (int i = 1; i <= n; i ++) {
		if (qq[loc].v > i) continue;
		memset(vis, 0, sizeof vis);
		bfs(i);
		for (int j = 1; j <= n; j ++) {
			if (vis[j]) {
				if (j == i) {
					st[0][j] = 0;
				} else {
					st[0][j] = getNt(j);
				}
			}
		}
		for (int j = 1; j <= 15; j ++) {
			for (int k = 1; k <= n; k ++) {
				st[j][k] = st[j - 1][st[j - 1][k]];
			}
		}
		while (loc <= q && qq[loc].v == i) {
			int k = qq[loc].k, v = i, u = qq[loc].u;
			if (!vis[u] || st[15][u]) {
				ans[qq[loc].id] = -1;
			} else {
				k --;
				for (int j = 0; j <= 15; j ++) {
					if (k & (1 << j)) {
						u = st[j][u];
					}
				}
				if (u) ans[qq[loc].id] = u;
				else ans[qq[loc].id] = -1;
			}
			++ loc;
		}
		if (q < loc) break;
	}
	for (int i = 1; i <= q; i ++) {
		printf("%d\n", ans[i]);
	}
}
