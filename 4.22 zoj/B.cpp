#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int t;
	int s[1000];
	scanf("%d",&t);
	while (t --) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; i ++) {
			scanf("%d",&s[i]);
		}
		if (n < 10 || n > 13) {
			puts("No");
			continue;
		}
		sort(s, s + n);
		if (s[0] != 1 || s[1] != 1) {
			puts("No");
			continue;
		}
		int flag = 1;
		for (int i = 2; i < n - 1; i ++) {
			if (s[i] - s[i - 1] > 2) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
}
