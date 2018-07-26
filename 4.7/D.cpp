#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int num[100010];
	int ans[100010];
	scanf("%d",&n);
	for (int i = 1; i <= n ; i ++) {
		scanf("%d",&num[i]);
	}
	int maxn = num[n];
	ans[n] = 0;
	for (int i = n - 1; i >= 1; i --) {
		ans[i] = (maxn + 1) - num[i];
		if (ans[i] < 0) ans[i] = 0;
		maxn = max(maxn, num[i]);
	}
	printf("%d",ans[1]);
	for (int i = 2; i <= n; i ++)
		printf(" %d",ans[i]);
	printf("\n");
}
