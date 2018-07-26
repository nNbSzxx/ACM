#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, a[200005];
	while (~scanf("%d",&n), n) {
		int ans = 0;
		for (int i = 1; i <= n ; i ++) {
			scanf("%d",&a[i]);
			ans ^= a[i];
		}
		if (ans == 0) {
			puts("No");
			continue;
		}
		puts("Yes");
		for (int i = 1; i <= n; i ++) {
			int l = ans ^ a[i];
			if (a[i] > l) {
				printf("%d %d\n", a[i], l);
			}
		} 
	}
	return 0;
}
