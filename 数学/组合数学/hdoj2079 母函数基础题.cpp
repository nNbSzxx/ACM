#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int t,n,k;
	int scr[10], sum[10];
	int a[100], b[100];
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&k);
		for (int i = 1; i <= k; i ++) {
			scanf("%d%d", &scr[i], &sum[i]);
		}
		memset(a, 0, sizeof(a));
		a[0] = 1;
		for (int i = 1; i <= k; i ++) {
			memset(b, 0, sizeof(b));
			for (int j = 0; j <= n && j <= sum[i] * scr[i]; j += scr[i]) {
				for (int k = 0; k + j <= n; k ++) {
					b[j + k] += a[k];
				}
			}
			memcpy(a, b, sizeof(a));
		}
		printf("%d\n", a[n]);
	}
	return 0;
}
