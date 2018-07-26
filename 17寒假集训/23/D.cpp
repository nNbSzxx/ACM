#include <iostream>
#include <cstdio>
#include <cstring>
#define lowbit(x) ((x)&(-x))
using namespace std;

const int MAX = 5010;
const int INF = 0x3f3f3f3f;
int tree[MAX + 5];

int query(int k)
{
	int ret  = 0;
	while (k) {
		ret += tree[k];
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

int main()
{
	int n;
	int num[MAX];
	while (~scanf("%d",&n)) {
		memset(tree,0,sizeof(tree));
		int ans = INF;
		int temp = 0;
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d",&num[i]);
			num[i] ++;
			update(num[i],1);
			temp += i - query(num[i]);
		}
		ans = temp;
		for (int i = 1; i <= n ; i ++) {
			temp = temp - num[i] + 1 + n - num[i];
			if (ans > temp) ans = temp;
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
