#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX = 100005;
int father[MAX];
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
int main()
{
	int x,y,visit[MAX];
	while (scanf("%d%d",&x,&y), x != -1 && y != -1) {
		for (int i = 1; i <= 100000; i ++) {
			father[i] = i;
		}
		memset(visit,0,sizeof(visit));
		if (x && y) {
			unite(x, y);
			visit[x] = visit[y] = 1;
		} else {
			puts("Yes");
			continue;
		}
		int flag = 1;
		while (scanf("%d%d",&x,&y), x || y) {
			visit[x] = visit[y] = 1;
			int xx = find(x);
			int yy = find(y);
			if (flag) {
				if (xx == yy) {
					flag = 0;
				} else {
					unite(x,y);
				}		
			}
		}
		int cnt = 0;
		if (flag) {
			for (int i = 1; i <= 100000; i ++) {
				if (visit[i] && i == father[i]) {
					cnt ++;
				}
			}
			if (cnt != 1) {
				flag = 0;
			}
		} 
		if (flag) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
