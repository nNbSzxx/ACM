#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;
int n, m, f[105], t;
int sg[10010] ;
// f[i]ÊÇ²ßÂÔ¼¯ 
int dfsSG(int x)
{
	if (sg[x] != -1) return sg[x];
	int vis[110];
	memset(vis,0,sizeof(vis));
	for (int i = 0; f[i] <= x && i < n; i ++) {
		dfsSG(x - f[i]);
		vis[sg[x - f[i]]] = 1;
	}
	for (int i = 0; ;i ++) {
		if (!vis[i]) {
			return sg[x] = i;
		}
	}
}

int main()
{
	while (~scanf("%d",&n), n) {
		for(int i = 0; i < n; i ++) {
			scanf("%d",&f[i]);
		}
		memset(sg, -1, sizeof(sg));
		sort(f,f+n);
		scanf("%d",&m);
		while (m --) {
			int ans = 0;
			scanf("%d",&t);
			int tt;
			for (int i = 1; i <= t; i ++) {
				scanf("%d",&tt);
				ans ^= dfsSG(tt);
			}
			if (ans) printf("W");
			else printf("L");
		}
		printf("\n");
	}
}
