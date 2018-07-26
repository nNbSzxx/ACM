#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX = 2005;
int father[MAX], dis[MAX];
int flag, n, m;

int find(int x)
{
	if (x != father[x]) {
		int ret = find(father[x]);
		dis[x] = (dis[x] + dis[father[x]]) % 2;
		father[x] = ret;
		return ret;
	}
	return x;
}
void merge(int x, int y)
{
	int xx = find(x);
	int yy = find(y);
	if (xx == yy) {
		if (dis[x] == dis[y]) {
			flag = 0;
		}
	} else {
		father[xx] = yy;
		dis[xx] = (dis[y] + dis[x] + 1) % 2;
	}
	return ;
}
void init(void)
{
	flag = 1;
	memset(dis, 0, sizeof(dis));
	for (int i = 1; i <= n; i ++) {
		father[i] = i;
	}
}
int main()
{
	int tc = 0, t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &m);
		init();
		int x, y;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d", &x, &y);
			if (flag)
				merge(x, y);
		}
		printf("Scenario #%d:\n", ++tc);
		if (flag)
			puts("No suspicious bugs found!\n"); 
		else 
			puts("Suspicious bugs found!\n");
	}
	return 0;
}



