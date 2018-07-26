#include <bits/stdc++.h>
using namespace std;
int a[100010];

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		int n;
		scanf("%d", &n);
		for (int i = 2; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		if (n & 1) {
			puts("No");
			continue;
		}
		int cnt = 0;
		int flag = 1;
		for (int i = n; i > 1; i --) {
			if (a[i] == 1) {
				++ cnt;
			} else {
				-- cnt;
				if (cnt < 0) {
					flag = 0;
				}
			}
		}
		if (flag) {
			puts("Yes"); 
		} else {
			puts("No");
		}
	}
	return 0;
}
