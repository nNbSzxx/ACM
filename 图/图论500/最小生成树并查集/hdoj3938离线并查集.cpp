#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 5e4 + 5;
const int N = 1e4 + 5;
int father[N], sum[N], ans[N];
int n, m, t;
struct edge {
	int u, v, w;
} e[M];
struct query {
	int id, l;
} q[N];
bool cmp(const edge &e1, const edge &e2)
{
	return e1.w < e2.w;
}
bool cmp1(const query &q1, const query &q2)
{
	return q1.l < q2.l;
}
int find(int x)
{
	while (x != father[x]) {
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}
int merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y) {
		father[y] = x;
		sum[x] += sum[y];
		return (sum[x] - sum[y]) * sum[y];
	} else return 0;
}
void init(void)
{
	for (int i = 1; i <= n; i ++) {
		sum[i] = 1;
		father[i] = i;
	}
}
int main()
{
	while (~scanf("%d%d%d", &n, &m, &t)) {
		init();
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		}
		sort(e + 1, e + 1 + m, cmp);
		for (int i = 1; i <= t; i ++) {
			scanf("%d",&q[i].l);
			q[i].id = i;
		}
		sort(q + 1, q + 1 + t, cmp1);
		int cnt = 0, j = 1;
		for (int i = 1; i <= t; i ++) {
			while (j <= m && e[j].w <= q[i].l) {
				cnt += merge(e[j].u, e[j].v);
				++ j;
			}
			ans[q[i].id] = cnt;
		}
		for (int i = 1; i <= t; i ++) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}





