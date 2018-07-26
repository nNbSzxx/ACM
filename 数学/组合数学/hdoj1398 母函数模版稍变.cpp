#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	int b[310],a[310];;
	while (~scanf("%d",&n), n) {
		memset(a, 0 ,sizeof(a));
		a[0] = 1;
		for (int i = 1; i <= n; i ++) {
			memset(b, 0, sizeof(b));
			for (int j = 0; j <= n; j += i * i) {
				for (int k = 0; k + j <= n; k ++) {
					b[k + j] += a[k];
				}
			}
			memcpy(a, b, sizeof(b));
		}
		printf("%d\n", a[n]);
	}
	return 0;
}
