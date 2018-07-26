#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int father[220];
const int INF = 0x3f3f3f3f;
struct edge{
	int u,v,w;
} e[1010];
int find(int x)
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
	if (x != y)
		father[x] = y;
	return ;
}

bool cmp(edge& e1, edge& e2)
{
	return e1.w < e2.w;
}
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m)) {
		for (int i = 0; i < m; i ++) {
			scanf("%d%d%d",&e[i].u, &e[i].v, &e[i].w);
		}
		sort(e, e + m, cmp);
		int q;
		scanf("%d", &q);
		while (q --) {
			int a, b;
			scanf("%d%d",&a,&b);
			int ans = INF;
			for (int i = 0; i < m; i ++) {
				for (int j = 1; j <= n; j ++) {
					father[j] = j;
				}
				for (int j = i; j < m; j ++) {
					merge(e[j].u,e[j].v);
					if (find(a) == find(b)) {
						ans = min(ans, e[j].w - e[i].w);
						break;
					}
				}
			}
			if (ans != INF)
				printf("%d\n",ans);
			else
				puts("-1");
		}
		
	}
	return 0;
}
