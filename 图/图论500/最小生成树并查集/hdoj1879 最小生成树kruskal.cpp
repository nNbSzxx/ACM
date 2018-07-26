#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct edge {
	int u,v,w;
} e[10000];
int father[150], cnt;

bool cmp(edge& e1, edge& e2)
{
	return e1.w < e2.w;
}

int find (int x)
{
	while (x != father[x]) {
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y) {
		father[x] = y;
		-- cnt;
	}
}
int main()
{
	int n;
	int cnte;
	while (~scanf("%d",&n), n) {
		for (int i = 1; i <= n; i ++) {
			father[i] = i;
		}
		cnt = n - 1;
		cnte = 0;
		int u,v,w,t;
		for (int i = 1; i <= n * ( n - 1) / 2; i ++) {
			scanf("%d%d%d%d",&u,&v,&w,&t);
			if (t) {
				merge(u, v);
			} else {
				e[cnte].u = u;
				e[cnte].v = v;
				e[cnte].w = w;
				++ cnte;
			}
		}
		sort(e, e + cnte, cmp);
		int i = 0;
		int ans = 0;
		while (cnt) {
			if (find(e[i].u) != find(e[i].v)) {
				merge(e[i].u, e[i].v);
				ans += e[i].w;
			}
			++ i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
