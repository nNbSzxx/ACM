#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX = 1005;
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
		father[b] = a;
	return ;
}

int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; i ++) {
			father[i] = i;
		}
		for (int i = 1; i <= m ; i ++) {
			int a,b;
			scanf("%d%d",&a,&b);
			unite(a,b);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (father[i] == i) {
				cnt ++;
			}
		}
		printf("%d\n",cnt);	
	}
}
