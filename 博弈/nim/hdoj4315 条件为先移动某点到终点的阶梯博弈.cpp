#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010;
int a[MAX];
int n, k;

int main()
{
	while (~scanf("%d%d", &n, &k)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		if (k == 1) {
			puts("Alice");
			continue;
		}
		if (n & 1) a[0] = -1;
		if (k == 2 && (n & 1)) ++ a[0];
		int ans = 0;
		for (int i = n; i >= 1; i -= 2) {
			ans ^= (a[i] - a[i - 1] - 1);
		}
		if (ans) {
			puts("Alice");
		} else {
			puts("Bob");
		}
	}
}
