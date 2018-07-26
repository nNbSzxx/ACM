#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct E {
	int u,v,w;
} e[5050];
int father[110];
int find(int x)
{
	while (x != father[x]) {
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		father[x] = y;
	return ;
}
bool cmp(E& e1, E& e2)
{
	return e1.w < e2.w;
}
int main()
{
	int n,m;
	while (~scanf("%d",&m), m) {
		scanf("%d",&n);
		for (int i = 1; i <= n; i ++) {
			father[i] = i;
		}
		for (int i = 0; i < m; i ++) {
			scanf("%d%d%d",&e[i].u, &e[i].v, &e[i].w);
		}
		int ans = 0, cnt = 0;
		sort(e, e + m, cmp);
		for (int i = 0; i < m; i ++) {
			if (find(e[i].u) != find(e[i].v)) {
				unite(e[i].u, e[i].v);
				ans += e[i].w;
				cnt ++;
			}
			if (cnt == n - 1) {
				break;
			}
		}
		if (cnt == n - 1) {
			printf("%d\n", ans);
		} else {
			printf("?\n");
		}
	}
	
	return 0;
}
