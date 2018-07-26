#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100010;

int main()
{
	int n,c,a[MAX], mod[MAX];
	long long sum[MAX];
	while (~scanf("%d%d",&c,&n), n || c) {
		sum[0] = 0;
		memset(mod,0,sizeof(mod));
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 1; i <= n; i ++) {
			int m = sum[i] % c;
			if (m == 0) {
				printf("1");
				for (int j = 2; j <= i; j ++) 
					printf(" %d",j);
				break;
			}
			if (mod[m]) {
				printf("%d",mod[m] + 1);
				for (int j = mod[m] + 2; j <= i; j ++) {
					printf(" %d", j);
				}
				break;
			}
			mod[m] = i;
		}
		printf("\n");
	}
	return 0;
}
