#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 2e5 + 10;
int n;
int p[MAX];
int c[MAX];
int vis[MAX], indeg[MAX], paid[MAX], hasfind[MAX];
long long ans;

void findminn(int x)
{
	if (paid[x] || hasfind[x]) {
		return ;
	}
	hasfind[x] = 1;
	int minn = c[x], id = x;
	int b = p[x];
	while (b != x) {
		if (paid[b] || hasfind[b]) {
			return ;
		}
		if (c[b] < minn) {
			minn = c[b];
			id = b;
		}
		hasfind[b] = 1;
		b = p[b];
	}
	ans += minn;
	paid[id] = 1;
	return ;
}

int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &c[i]);
		}
		memset(indeg, 0, sizeof indeg);
		memset(vis, 0, sizeof vis);
		memset(paid, 0, sizeof paid);
		ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &p[i]);
			++ indeg[p[i]];
		}
		for (int i = 1; i <= n; i ++) {
			if (!indeg[i] && !vis[i]) {
				int b = i;
				while (true) {
					if (vis[b]) {
						findminn(b);
						break;
					}
					vis[b] = 1;
					b = p[b];
				}
			}
		}
		//printf("%lld\n", ans);
		for (int i = 1; i <= n; i ++) {
			if (!vis[i]) {
				findminn(i);
				vis[i] = 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
