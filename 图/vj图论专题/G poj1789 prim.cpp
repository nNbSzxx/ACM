#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 2010;
const int INF = 0x3f3f3f3f;
int map[MAX][MAX];
int lowcost[MAX], n;
int visit[MAX];

inline int Min(int a, int b)
{
	return a > b? b : a;
}

int edge(char *s1, char *s2)
{
	int len = 0;
	for (int i = 0; i < 7; i ++) {
		if (s1[i] != s2[i]) {
			len ++;
		}
	}
	return len;
}

int prim(void)
{
	int ans = 0;
	memset(visit,0,sizeof(visit));
	for (int i = 1; i < n; i ++) {
		lowcost[i] = map[0][i];
	}
	lowcost[0] = 0;
	visit[0] = 1;
	
	for (int i = 1; i < n; i ++) {
		int min = INF, minid;
		for (int j = 0; j < n; j ++) {
			if (min > lowcost[j] && !visit[j]) {
				min = lowcost[j];
				minid = j;
			}
		}
		ans += lowcost[minid];
		visit[minid] = 1;
		lowcost[minid] = 0;
		for (int j = 0; j < n; j ++) {
			if (map[minid][j] != INF ) {
				lowcost[j] = Min(map[minid][j], lowcost[j]);
			}
		}

	}
	return ans;
}

int main()
{
	char s[MAX][8];
	while (~scanf("%d",&n), n) {
		memset(map,0x3f,sizeof(map));
		for (int i = 0; i < n;i ++) {
			scanf("%s",s[i]);
			for (int j = 0; j < i; j ++) {
				map[i][j] = map[j][i] = edge(s[i],s[j]);
			}
		}
		int ans = prim();
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	return 0;
}
