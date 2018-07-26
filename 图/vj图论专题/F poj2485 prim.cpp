#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 510;
const int INF = 0x3f3f3f3f;
int map[MAXN][MAXN];
int n;
int visit[MAXN];

inline int Min(int a, int b)
{
	return a > b? b : a;
}

int prim(void)
{
	int ans = 0;
	int lowcost[MAXN];
	memset(visit,0,sizeof(visit));
	for (int i = 2; i <= n; i ++) {
		lowcost[i] = map[1][i];
	}
	lowcost[1] = 0;
	visit[1] = 1;
	for (int i = 1; i < n; i ++) {
		int min = INF, minid;
		for (int j = 1; j <= n ; j ++) {
			if (!visit[j] && lowcost[j] < min) {
				min = lowcost[j];
				minid = j;
			}
		}
		visit[minid] = 1;
		if (ans < lowcost[minid]) {
			ans = lowcost[minid];
		}
		for (int j = 1; j <= n ; j ++) {
			lowcost[j] = Min(lowcost[j], map[minid][j]);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while (t --) {
		scanf("%d",&n);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				scanf("%d",&map[i][j]);
			}
		}
		int ans = prim();
		printf("%d\n",ans);
	}

	return 0;
}
