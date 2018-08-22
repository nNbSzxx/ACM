#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 10;
int dp[MAX];
int p[MAX];
int b[MAX];
int n, cnt;

int bins(int x)
{
	int l = 1, r = cnt, ret = 0, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (dp[mid] < x) {
			ret = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int a;
		scanf("%d", &a);
		p[a] = i;
	}
	for (int i = 1; i <= n; i ++) {
		int a;
		scanf("%d", &a);
		b[n - p[a] + 1] = i;
	}
	cnt = 0;
	for (int i = 1; i <= n; i ++) {
		int id = bins(b[i]);
		if (id == cnt) {
			++ cnt;
			dp[cnt] = b[i];
		} else {
			dp[id + 1] = b[i];
		}
	}
	
	printf("%d\n", cnt);
	return 0;
}
