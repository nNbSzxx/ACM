#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 130;

int main()
{
	int n;
	int a[MAX], b[MAX];
	while (~scanf("%d",&n)) {
		for (int i = 0; i <= n; i ++) {
			a[i] = 1;
		}
		for (int i = 2; i <= n; i ++) {
			memset(b, 0, sizeof(b));
			for (int j = 0; j <= n; j ++) {
				for (int k = 0; k + j <= n; k += i) {
					b[k + j] += a[j];
				}
			}
			memcpy(a, b, sizeof(b));
		}
		printf("%d\n",a[n]);
	}
	return 0;
}
