#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;
int m, k, p, cnt, head[MAX], d[MAX];
struct E{
	int v, nt;
} e[MAX * 2];
void add(int u, int v)
{
	e[cnt].v = v;
	e[cnt].nt = head[u];
	head[u] = cnt;
	++ cnt;
	return ;
}
void dfs(int u, int fa)
{
	for (int i = head[u]; i; i = e[i].nt) {
		if (e[i].v != fa) {
			d[e[i].v] = d[u] + 1;
			dfs(e[i].v, u);
		}
	}
	return ;
}
int main()
{
	scanf("%d%d%d", &m, &k, &p);
	cnt = 1;
	memset(head, 0, sizeof(head));
	int u, v;
	for (int i = 1; i < m; i ++) {
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	d[1] = 1;
	dfs(1, -1);
	sort(d + 1, d + 1 + m);
	int i = 2, j = 1;
	long long cost = 0;
	int ans = 0;
	while (j < m) {
		++ j;
		if (d[j] > d[j - 1]) {
			cost += j - i;
		}
		while (cost > p) {
			cost -= d[j] - d[i];
			++ i;
		}
		ans = max(ans, j - i + 1);
	}
	printf("%d\n", min(ans, k));
	return 0;
}
