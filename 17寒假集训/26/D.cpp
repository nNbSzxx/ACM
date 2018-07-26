#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 200005;

int main()
{
	int n;
	int num[MAX];
	while (scanf("%d",&n), n) {
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&num[i]);
			ans ^= num[i];
		}
		if (ans == 0) {
			puts("No");
			continue;
		}
		puts("Yes");
		int lea;
		for (int i = 1; i <= n; i ++) {
			lea = ans ^ num[i];
			if (num[i] > lea) {
				printf("%d %d\n",num[i],lea);
			}
		}
	}
	return 0;
}
