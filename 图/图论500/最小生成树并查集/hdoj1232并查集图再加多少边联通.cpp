#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX = 1005;
int n,m,cnt;
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
	if (a != b) {
		cnt --;
		father[a] = b;
	}
	return ;
}
int main()
{
	while (scanf("%d",&n), n) {
		cnt = n - 1;
		scanf("%d",&m);
		for (int i = 1; i <= n; i ++) {
			father[i] = i;
		}
		int a,b;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d",&a,&b);
			unite(a,b);
		}
		printf("%d\n",cnt);
	}
	return 0;
}
