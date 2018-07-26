#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 5050;
int a[MAX], f[MAX];
int n;

int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i ++) {
			char c;
			scanf(" %c", &c);
			if (c == 'B') {
				a[i] = 1;
			} else {
				a[i] = 0;
			}
		}
		int ansk = 0, ansm = MAX;
		for (int k = 1; k <= n; k ++) {
			int m = 0, sum = 0;
			memset(f, 0, (n + 1) * sizeof(int));
			for (int i = 1; i + k <= n + 1; i ++) {
				if (i - k >= 1) {
					sum ^= f[i - k];
				}
				if (a[i] ^ sum == 1) {
					++ m;
					sum ^= 1;
					f[i] = 1;
				}
			}
			int flag = 1;
			for (int i = n - k + 2; i <= n; i ++) {
				if (i - k >= 1) {
					sum ^= f[i - k];
				}
				if (a[i] ^ sum == 1) {
					flag = 0;
					break;
				}
			}
			if (flag && m < ansm) {
				ansm = m;
				ansk = k;
			}
		}
		printf("%d %d\n", ansk, ansm);
	}
	return 0;
}
