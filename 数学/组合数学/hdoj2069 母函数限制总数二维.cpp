
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int w[5] = {1, 5, 10, 25, 50};
	int a[330][110], b[330][110];
	memset(a, 0, sizeof(a));
	for (int i = 0; i <= 100; i ++) {
		a[i][i] = 1;
	}
	for (int i = 1; i <= 4; i ++) {
		memset(b, 0, sizeof(b));
		for (int j = 0; j <= 300; j += w[i]) {
			for (int k = 0; k + j <= 300; k ++) {
				for (int l = 0; l + j / w[i] <= 100; l ++) {
					b[j + k][l + j / w[i]] += a[k][l];
				}
			}
		}
		memcpy(a, b, sizeof(a));
	}
	
	while (~scanf("%d",&n)) {
		int ans = 0;
		for (int i = 0; i <= 100; i ++) {
			ans += a[n][i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
