#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 110;
int cnt[MAX];
int n;

int main()
{
	while (~scanf("%d", &n), n) {
		int a;
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a);
			++ cnt[a];
		}
		if (n & 1) {
			puts("1");
		} else {
			int sym = 1;
			for (int i = 1; i <= 100; i ++) {
				if (cnt[i] & 1) {
					sym = 0;
					break;
				}
			}
			printf("%d\n", !sym);
		}
	}
	
	return 0;
}
