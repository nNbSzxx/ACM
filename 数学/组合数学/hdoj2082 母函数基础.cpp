#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int t, a[55], b[55], num[30];
	scanf("%d",&t);
	while (t --) {
		for (int i = 1; i <= 26; i ++) {
			scanf("%d",&num[i]);
		}
		memset(a, 0 ,sizeof(a));
		a[0] = 1;
		for (int i = 1; i <= 26; i ++) {
			memset(b, 0, sizeof(b));
			for (int j = 0; j <= 50 && j <= num[i] * i; j += i) {
				for (int k = 0; k + j <= 50; k ++) {
					b[k + j] += a[k];
				}
			}
			memcpy(a, b, sizeof(b));
		}
		long long sum = 0;
		for (int i = 1; i <= 50; i ++) {
			sum += a[i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
