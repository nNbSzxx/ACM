#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 10;
const int INF = 1e9 + 10; 
int n, m, x[MAX];

bool check(int mid)
{
	int last = x[1];
	int i = 2, j = 2;
	while (j <= m) {
		while (i <= n && x[i] - last < mid) ++ i;
		if (i > n) return false;
		last = x[i];
		++ i; ++ j;
	}
	return true;
}

int bins()
{
	int ret = 0;
	int l = 0, r = INF;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ret = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ret;
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &x[i]);
		}
		sort(x + 1, x + 1 + n);
		int ans = bins();
		printf("%d\n", ans); 
	}
	return 0;
}
