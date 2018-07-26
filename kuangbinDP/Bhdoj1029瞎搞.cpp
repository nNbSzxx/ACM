#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while (~scanf("%d", &n)) {
		int cnt = 1;
		int now, t;
		scanf("%d", &now);
		for (int i = 2; i <= n; i ++) {
			scanf("%d", &t);
			if (now == t)
				++ cnt;
			else {
				-- cnt;
				if (cnt == -1) {
					cnt = 1;
					now = t;
				}
			}
		}
		printf("%d\n", now);
	}
	return 0;
}
