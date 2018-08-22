#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 2e5 + 10;
int a[MAX];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int ans = a[k];
	if (k == n) {
		printf("%d\n", ans);
	} else if (k == 1) {
		if (a[k] == a[k + 1]) {
			puts("-1");
		} else {
			printf("%d\n", ans);
		}
	} else if (k == 0) {
		if (a[1] == 1) {
			puts("-1");
		} else {
			printf("%d", a[1] - 1);
		}
	} else {
		if (a[k] == a[k + 1]) {
			puts("-1");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
