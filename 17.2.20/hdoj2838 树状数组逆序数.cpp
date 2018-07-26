#include <iostream>
#include <cstdio>
#include <cstring>
#define lowbit(x) ((x)&(-x))
using namespace std;

const int MAX = 100010;
__int64 tree[MAX + 5];
__int64 treesum[MAX + 5];

__int64 query(int k)
{
	__int64 ret  = 0;
	while (k) {
		ret += tree[k];
		k -= lowbit(k);
	}
	return ret;
}

__int64 querysum(int k)
{
	__int64 ret = 0;
	while (k) {
		ret += treesum[k];
		k -= lowbit(k);
	}
	return ret;
}

void update(int x, int v)
{
	while (x <= MAX) {
		tree[x] += v;
		x += lowbit(x);
	}
	return ;
}

void updatesum(int x, int v)
{
	while (x <= MAX) {
		treesum[x] += v;
		x += lowbit(x);
	}
	return ;
}

int main()
{
	int n;
	while (~scanf("%d",&n)) {
		memset(tree,0,sizeof(tree));
		memset(treesum,0,sizeof(treesum));
		__int64 ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int m;
			scanf("%d",&m);
			update(m,1);
			updatesum(m,m);
			__int64 num = i + 1 - query(m);
			ans += num * m + querysum(n) - querysum(m);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
