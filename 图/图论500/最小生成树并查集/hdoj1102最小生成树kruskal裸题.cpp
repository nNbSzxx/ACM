#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 105;
int father[MAX];
struct edge {
	int u,v,w;
}e[MAX*MAX];
int find(int x)
{
	while (x != father[x]) {
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}
void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		father[a] = b;
	return ;
}
bool cmp(edge& a, edge& b)
{
	return a.w < b.w;
}
int main()
{
	int n,m,cnt,w;
	while (~scanf("%d",&n)) {
		cnt = 0;
		for (int i = 1; i <= n; i ++) {
			father[i] = i;
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n;j ++) {
				scanf("%d",&w);
				if (j < i) {
					e[cnt].u = i;
					e[cnt].v = j;
					e[cnt ++].w = w;
				}
			}
		}
		scanf("%d",&m);
		int u,v;
		for (int i = 1; i <= m ; i ++) {
			scanf("%d%d",&u,&v);
			unite(u,v);
		}
		sort(e,e+cnt,cmp);
		int ans = 0;
		for (int i = 0; i < cnt; i ++) {
			if (find(e[i].u) != find(e[i].v)) {
				ans += e[i].w;
				unite(e[i].u, e[i].v);
			}
		}
		printf("%d\n",ans);
	}
	
}
