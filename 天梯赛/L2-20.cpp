#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
struct edge {
	int v, nt;
} e[MAX];
int n, cnt = 1, mul[MAX], head[MAX];
double z, r;

void add(int u, int v)
{
	e[cnt].v = v;
	e[cnt].nt = head[u];
	head[u] = cnt;
	++ cnt;
}

double dfs(int x, double weak)
{
	double ret = 0;
	if (mul[x] != -1) {
		// printf("%d %d %.2lf %.2lf\n", x, mul[x], weak, z * weak * mul[x]);
		return (z * weak * mul[x]);
	}
	for (int i = head[x]; i; i = e[i].nt) {
		ret += dfs(e[i].v, weak * 1.0 * (100.0 - r) / 100.0);	
	}
	return ret;
}

int main()
{
	memset(head, 0, sizeof head);
	memset(mul, -1, sizeof mul);
	scanf("%d%lf%lf", &n, &z, &r);
	for (int i = 1; i <= n; i ++) {
		int k;
		scanf("%d", &k);
		if (k == 0) {
			scanf("%d", &mul[i]);
		} else {
			int v;
			for (int j = 1; j <= k; j ++) {
				scanf("%d", &v);
				add(i, v + 1);
			}
		}
	}
	long long ans = dfs(1, 1);
	printf("%lld\n", ans);
}
