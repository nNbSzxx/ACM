#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n;

int main()
{
	scanf("%d", &n);
	int ans = n + n / 2;
	printf("%d\n", ans);
	for (int i = 2; i <= n; i += 2) {
		printf("%d ", i);
	}
	for (int i = 1; i <= n; i += 2) {
		printf("%d ", i);
	}
	for (int i = 2; i <= n; i += 2) {
		printf("%d ", i);
	}
	puts("");
}
