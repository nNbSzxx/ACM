#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;
int color[MAX], siz[MAX], sum[MAX], n, cnt;
int head[MAX];
long long ans;

struct edge {
	int v, nt;
} e[MAX * 2];

void add(int u, int v)
{
	e[cnt].v = v;
	e[cnt].nt = head[u];
	head[u] = cnt ++;
	return ;
}

void init(void)
{
	ans = (long long)n * n * (n - 1) / 2;
	cnt = 1;
	memset(sum, 0, sizeof(sum));
	memset(head, 0, sizeof(head));
	memset(siz, 0, sizeof(siz));
}

void dfs(int x, int fa)
{
	siz[x] = 1;
	int pre = sum[color[x]];
	int add = 0;
	for (int i = head[x]; i; i = e[i].nt) {
		int v = e[i].v;
		if (v == fa)
			continue;
		dfs(v, x);
		
		siz[x] += siz[v];
		int temp = siz[v] - sum[color[x]] + pre;
		add += temp;
		ans -= (long long)(temp - 1) * temp / 2;
		pre = sum[color[x]];
	}
	
	sum[color[x]] += add + 1;
}
int main()
{
	int t = 1;
	while (~scanf("%d", &n)) {
		init();
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &color[i]);
		}
		int u, v;
		for (int i = 1; i < n; i ++) {
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		dfs(1, -1);
		for (int i = 1; i <= n; i ++) {
			int temp = n - sum[i];
			ans -= (long long)(temp - 1) * temp / 2;
		}
		printf("Case #%d: %lld\n", t ++, ans);
	}
}
