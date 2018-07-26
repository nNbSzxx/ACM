#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	int a[10010], sum[10010], mod[10010];
	while (~scanf("%d",&n)) {
		sum[0] = 0;
		memset(mod, 0, sizeof(mod));
		for (int i = 1; i <= n ; i ++) {
			scanf("%d",&a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 1; i <= n; i ++) {
			int m = sum[i] % n;
			if (m == 0) {
				printf("%d\n", i);
				for (int j = 1; j <= i; j ++) {
					printf("%d\n",a[j]);
				}
				break;
			}
			if (mod[m]) {
				printf("%d\n",i - mod[m]);
				for (int j = mod[m] + 1; j <= i; j ++) {
					printf("%d\n",a[j]);
				}
				break;
			}
			mod[m] = i;
		}
	}
	return 0;
}
