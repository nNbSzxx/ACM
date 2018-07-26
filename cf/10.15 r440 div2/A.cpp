#include <bits/stdc++.h>
using namespace std;
int a[100], b[100];

int main()
{
	int n, m, t;
	t = -1;
	int minn1 = -1, minn2 = -1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &t);
		a[t] = 1;
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &t);
		b[t] = 1;
	}
	int ans = -1;
	for (int i = 1; i <= 99; i ++) {
		if (i < 10) {
			if (a[i] && b[i]) {
				ans = i;
				break;
			}
		} else {
			int aa = i % 10, bb = i / 10;
			if (a[bb] && b[aa] || a[aa] && b[bb]) {
				ans = i;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
