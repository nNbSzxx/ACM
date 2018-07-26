#include <bits/stdc++.h>
using namespace std;
// 5 2
// 4 5 1 3 2
int main()
{
	int q;
	scanf("%d", &q);
	while (q --) {
		int n;
		scanf("%d", &n);
		if (n == 1 || n == 2 || n == 3) {
			puts("-1");
			continue;
		}
		if (n == 5 || n == 7 || n == 11) {
			puts("-1");
			continue;
		}
		if (n & 1) {
			printf("%d\n", (n - 9) / 4 + 1);
		} else {
			printf("%d\n", n / 4);
		}
	}
}
