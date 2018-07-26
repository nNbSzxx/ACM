#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,p,f[100],sum;
int sg[1010];

int dfsSG (int x)
{
	if (sg[x] != -1) return sg[x];
	int vis[110];
	memset(vis, 0, sizeof(vis));
	for (int i = 0; f[i] <= x && i < sum; i ++) {
		dfsSG(x - f[i]);
		vis[sg[x - f[i]]] = 1;
	}
	for (int i = 0; ; i ++) {
		if (!vis[i])
			return sg[x] = i;
	}
}

int main()
{
	memset(sg, -1, sizeof(sg));
	f[0] = 1;
	f[1] = 2;
	int i;
	for (i = 2; f[i - 1] <= 1000; i ++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	sum = i;
	while (~scanf("%d%d%d",&n,&m,&p), n || m || p) {
		int ans = 0;
		ans = dfsSG(n) ^ dfsSG(m) ^ dfsSG(p);
		if (ans) {
			printf("Fibo\n");
		} else {
			printf("Nacci\n");
		}
	}
	return 0;
}
