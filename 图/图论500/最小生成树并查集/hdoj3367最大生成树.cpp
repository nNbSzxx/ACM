#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
struct E{
	int u, v, w;
}e[100005];
int n, m, father[10005], flag[10005];
bool cmp(const E& e1, const E& e2)
{
	return e1.w > e2.w;
}
int find(int x)
{
	while (x != father[x]) {
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}
bool merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) {
		if (!flag[x]) {
			flag[x] = 1;
			return true;
		} else {
			return false;
		}
	}
	if (flag[x] && flag[y]) {
		return false;
	}
	if (!flag[x]) {
		father[x] = y;
	} else 
		father[y] = x;
	return true;
}
int main()
{
	while (~scanf("%d%d", &n, &m), m || n) {
		for (int i = 0; i < n; i ++) {
			father[i] = i;
		}
		memset(flag, 0, sizeof(flag));
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		sort(e+1, e + 1 + m, cmp);
		int cnt = 0;
		int ans = 0;
		bool flag = 0;
		for (int i = 1; i <= m && cnt < n; i ++) {
			if (merge(e[i].u, e[i].v)) {
				ans += e[i].w;
				++ cnt;
			}
		}
		printf("%d\n", ans);
	}
}
