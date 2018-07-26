#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 100005;
int tree[MAX + 5];

inline int lowbit(int x)
{
	return x & ~(x - 1);
}

void update(int k, int v)
{
	while (k) {
		tree[k] += v;
		k -= lowbit(k);
	}
}

int query(int k)
{
	int ans = 0;
	while (k <= MAX) {
		ans += tree[k];
		k += lowbit(k);
	}
	return ans;
}

int main()
{
	int n;
	while (~scanf("%d",&n), n) {
		memset(tree,0,sizeof(tree));
		for (int i = 0; i < n ; i ++) {
			int a,b;
			scanf("%d%d",&a,&b);
			update(b,1);
			update(a-1,-1);
		}
		printf("%d",query(1));
		for (int i = 2; i <= n; ++i)
		{
			printf(" %d", query(i));
		}
		printf("\n");
	}
	return 0;
}
