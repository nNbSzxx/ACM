#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
int n, k;
pair<int, int> sum[MAX];

int main()
{
	while (~scanf("%d%d", &n, &k), n || k) {
		sum[0] = make_pair(0, 0);
		for (int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			sum[i] = make_pair(sum[i - 1].first + x, i);
		}
		sort(sum, sum + 1 + n);
		while (k --) {
			int t;
			scanf("%d", &t);
			int i = 0, j = 0;
			int l = -1, r = -1, ans = -(1e9 + 10);
			while (true) {
				if (i == j) {
					++ j;
				}
				if (j > n) {
					break;
				}
				int value = sum[j].first - sum[i].first;
				if (abs(value - t) < abs(ans - t)) {
					ans = value;
					l = sum[i].second;
					r = sum[j].second;
				}
				if (value > t) {
					++ i;
				} else if (value < t) {
					++ j;
				} else {
					break;
				}
			}
			if (l > r) {
				swap(l, r);
			}
			++ l;
			printf("%d %d %d\n", ans, l, r);
		}
	}
	return 0;
}
