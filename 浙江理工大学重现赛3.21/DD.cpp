#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n,m;
	int c[5];
	while (~scanf("%d%d",&n,&m)) {
		for (int i = 1; i <= 3; i ++) {
			scanf("%d",&c[i]);
		}
		int minn = min(min(c[1],c[2]),c[3]);
		int maxx = max(max(c[1],c[2]),c[3]);
		if (minn * m > n || maxx * m < n) {
			printf("No\n");
			continue;
		}
		int flag = 0;
		if (c[1] == c[2] && c[2] == c[3]) {
			if (c[1] * m == n) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			continue;
		}
		if (c[3] == c[1]) {
			int t = n - c[1] * m;
			if (t % (c[2] - c[1]) == 0) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			continue;
		}
		for (int y = 0; y <= m; y ++) {
			int z = (n - c[1] * m) - (c[2] - c[1]) * y;
			if (z % (c[3]- c[1]) == 0) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}
