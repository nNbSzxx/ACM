#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n, w;

int main()
{
	scanf("%d%d", &n, &w);
	int cur = 0;
	int minn = w + 1;
	int maxx = -1;
	for (int i = 1; i <= n ;i ++) {
		int a;
		scanf("%d", &a);
		cur += a;
		if (cur > maxx) {
			maxx = cur;
		}
		if (cur < minn) {
			minn = cur;
		}
	}
	int lb = 0, ub = w;
	if (minn < 0) {
		if (-minn > w) {
			puts("0");
			return 0;
		} else {
			lb = -minn;
		}
	}
	if (maxx > 0) {
		if (maxx > w) {
			puts("0");
			return 0;
		} else {
			ub = w - maxx;
		}
	}
	int ans = max(0, ub - lb + 1);
	printf("%d\n", ans);
	return 0;
}
