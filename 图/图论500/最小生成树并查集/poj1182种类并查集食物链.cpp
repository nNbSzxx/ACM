#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 50005;
int father[MAX], dis[MAX];
int n, m, ans;

int find(int x)
{
	if (x != father[x]) {
		int ret = find(father[x]);
		dis[x] = (dis[x] + dis[father[x]]) % 3;
		father[x] = ret;
		return ret;
	}
	return x;
}
// x eat y
void merge(int x, int y, int d)
{
	int xx = find(x);
	int yy = find(y);
	
	father[yy] = xx;
	// 连接的时候必须确保“代表节点”的dis值为0！ 
	dis[yy] = (dis[x] - dis[y] + d - 1 + 3) % 3;
	
	return ;
}
void init(void)
{
	memset(dis, 0, sizeof(dis));
	for (int i = 1; i <= n; i ++) {
		father[i] = i;
	}
	ans = 0;
	return ;
}
int main()
{
	scanf("%d%d", &n, &m);
	
	int x, y, d;
	init();		
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d%d", &d, &x, &y);
		if (x > n || y > n || (x == y && d == 2)) {
			ans ++;
			continue;
		} 
		int xx = find(x);
		int yy = find(y);
		if (xx == yy) {
			if (d == 1 && dis[x] != dis[y]) ++ ans;
			if (d == 2 && (dis[y] - dis[x] + 3) % 3 != 1) ++ ans; 
		} else {
			merge(x, y, d);
		}
	}
	printf("%d\n", ans);
	
	return 0;
}
