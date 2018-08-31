#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1010;
int a[MAX];
int n;

int main()
{
	while (~scanf("%d", &n), n) {
		int x = 0; 
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			x ^= a[i];
		}
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			int t = x ^ a[i];
			if (t < a[i]) {
				++ cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
