#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, t;
	scanf("%d%d", &n, &k);
	int maxx = -1e9 - 7, minn = +1e9 + 7;
	int fir, las;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &t);
		if (i == 1) fir = t;
		if (i == n) las = t;
		maxx = max(t, maxx);
		minn = min(t, minn);
	}
	if (k == 1) {
		printf("%d\n", minn);
	} else if (k == 2) {
		printf("%d\n", max(fir, las));
	} else {
		printf("%d\n", maxx);
	}
	return 0;
}
