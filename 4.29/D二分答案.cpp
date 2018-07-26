#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 3 * 1e5 + 10;
int t,n,k;
long long b[MAXN];
int ans;
long long len[MAXN];

bool isok (int m)
{
//	int pre = 0, now = 1;
	for (int i = 1; i <= m; i ++) {
		len[i] = b[i];
	}
	int p = m + 1;
	for (int i = 1; i < k; i ++) {
		for (int j = 1; j <= m; j ++) {
			while (p <= n && b[p] < len[j] * 2) {
				++ p;
			}
			if (p > n) return false;
			len[j] = b[p ++];
		}
//		swap(pre, now)
	}
	return true;
}
int bins (int l, int r)
{
	int ret = 0;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (isok(m)) {
			l = m + 1;
			ret = m;
		} else {
			r = m - 1;
		}
	}
	return ret;
}
int main()
{
	scanf("%d",&t);
	int tc = 1;
	while (t --) {
		scanf("%d%d",&n,&k);
		for (int i = 1; i <= n; i ++) {
			scanf("%lld",&b[i]);
		}
		sort (b + 1, b + 1 + n);
		printf("Case #%d: ",tc ++);
		printf("%d\n",bins(1, n / k));
		
	}
	return 0;
}



