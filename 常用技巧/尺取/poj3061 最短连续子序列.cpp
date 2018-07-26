#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
int a[MAX];
int n, s, t;

int main()
{
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &s);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		int len = MAX;
		int sum = 0;
		int l = 1, r = 1;
		while (true) {
			if (sum >= s) {
				sum -= a[l];
				++ l;
			} else {
				if (r == n + 1) {
					break;
				}
				sum += a[r];
				++ r;
			}
			if (sum >= s) {
				len = min(len, r - l);	
			}
		}
		if (len != MAX) {
			printf("%d\n", len);
		} else {
			puts("0");
		}
	}
	return 0;
}
