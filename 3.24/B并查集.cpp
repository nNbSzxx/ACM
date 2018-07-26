#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 150010;
int n,m;
int father[MAX];
int degree[MAX];
int cnt[MAX];

int find(int x)
{
	while (x != father[x])	{
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}
void binding(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		father[y] = x;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i ++) {
		father[i] = i;
	}
	int u,v;
	memset(cnt,0,sizeof(cnt));
	memset(degree,0,sizeof(degree));
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d",&u,&v);
		degree[u] ++;
		degree[v] ++;
		binding(u,v);
	}
	for (int i = 1; i <= n; i ++) {
		cnt[find(i)] ++;
	}
	int flag = 1;
	for (int i = 1; i <= n; i ++) {
		if (degree[i] != cnt[find(i)] - 1) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
} 
