#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e3 + 10;
int a[MAX];
int n;

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + 1 + n);
		if (n & 1) {
			a[0] = 0;
		}
		int ans = 0;
		for (int i = n; i >= 1; i -= 2) {
			ans ^= (a[i] - a[i - 1] - 1);
		}
		if (ans) {
			puts("Georgia will win");
		} else {
			puts("Bob will win");
		}
	}
	return 0;
}
