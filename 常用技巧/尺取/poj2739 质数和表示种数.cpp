#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e4 + 10;
int prime[MAX], vis[MAX], pcnt = 0;

void init()
{
	memset(vis, 0, sizeof vis);
	vis[1] = 1;
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[pcnt ++] = i;
			for (int j = 2 * i; j < MAX; j += i) {
				vis[j] = 1;
			}
		}
	}
}

int main()
{
	init();
	int n;
	while (~scanf("%d", &n), n) {
		int i = 0, j = 0;
		int cnt = 0, sum = 0;
		while (true) {
			if (sum > n) {
				sum -= prime[i];
				++ i;
			} else if (sum < n) {
				if (j >= pcnt) {
					break;
				}
				sum += prime[j];
				++ j;
			}
			if (sum == n) {
				++ cnt;
				sum -= prime[i];
				++ i;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
} 
