#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 32010;
int tree[MAX + 10];

int n;

int sum(int n)
{
	int ret = 0;
	while (n) {
		ret += tree[n];
		n -= n & ~(n - 1);
	}
	return ret;
}

void add(int x, int v)
{
	while (x <= MAX) {
		tree[x] += v;
		x += x & ~(x - 1);
	}
	return ;
}

int main()
{
	while (~scanf("%d",&n)) {
		int i;
		memset(tree,0,sizeof(tree));
		int ans[32010] = {0};
		for (i = 0; i < n ; i ++) {
			int x,y;
			scanf("%d%d",&x,&y);
			ans[sum(x + 1)] ++;
			add(x + 1, 1);
		}
		for (int i = 0; i < n; i ++) {
			printf("%d\n",ans[i]);
		}
	}
}
