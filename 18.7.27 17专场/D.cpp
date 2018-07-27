#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, k; 
long long c[15][15];
int a[1010][1010];

void init()
{
	c[0][0] = 1;
	for (int i = 1; i <= 10; i ++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j ++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
}

bool inbound(int x, int y)
{
	return x >= 1 && y <= m;
}

int main()
{
	init();
	scanf("%lld%lld%lld", &n, &m, &k);
	bool zero = false; 
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0) {
				zero = true;
			}
		}
	}
	if (n + m - 1 > k || !zero) {
		puts("0");
		return 0;
	}
	long long ans = 1;
	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j < m; j ++) {
			while (inbound(i - 1, j + 1) && a[i][j] && !a[i - 1][j + 1]) {
				swap(a[i][j], a[i - 1][j + 1]);
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= m; i ++) {
		if (a[1][i]) {
			++ cnt;
		}
	}
	for (int i = 2; i <= n; i ++) {
		if (a[i][m]) {
			++ cnt;
		}
	}
	int times = n + m - 1 - cnt;
	printf("%d %d\n", cnt, times);
	for (int i = k - cnt, j = 1; j <= times; i --, j ++) {
		ans = (ans * c[i][1]) % mod;
	}
	
	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j < m; j ++) {
			if (!a[i][j])
				ans = (ans * c[k - n - m + 2][1]) % mod;
		}
	}
	printf("%lld\n", ans);
	
	return 0;	
}
