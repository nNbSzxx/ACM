#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int t, n, m, k;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d", &n, &m, &k);
		if (k <= 0 || m <= 0) {
			continue;
		}
		if (m + k < n || m + k > n + 1) {
			continue;
		}
		if (n == 3 && (k == 1 || m == 1)) {
			continue;
		}
		if (n == 1) {
			printf("1\n");
			continue;
		}
		int cnt = 1;
		printf("%d", k);
		for (int i = k - 1; i >= 1; i --) {
			printf(" %d", i);
			++ cnt;
		}
		int flag = 0;
		for (int i = 1; i <= m - 2; i ++) {
			printf(" %d", i + k);
			++ flag;
			++ cnt;
		}
		
		int pre = k + flag + 1;
		int post = n;
		flag = 1;
		int now = post;

		for (int i = k + m - 1; i <= n; i ++) {
			if (cnt >= n) break;
			printf(" %d", now);
			++ cnt;
			if (!flag) {
				now = post;
				++ pre;
			} else {
				now = pre;
				-- post;
			}
		}
		printf("\n");
	}
	return 0;
}
