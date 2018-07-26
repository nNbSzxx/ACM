#include <cstdio>
using namespace std;

int main()
{
	int n;
	int a[110];
	while (~scanf("%d",&n), n) {
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
			ans ^= a[i];
		}
		if (ans == 0) {
			printf("0\n");
			continue;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			int lea = ans ^ a[i];
			if (a[i] > lea) {
				++ cnt;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
