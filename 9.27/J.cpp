#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
long long a[MAX], st[MAX][70];
int n, q;
long long v;
int l, r;

void init()
{
	for (int i = 1; i <= n; i ++) {
		st[i][0] = a[i];
	}
	for (int j = 1; (1 << j) <= n; j ++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i ++) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

long long query(int l, int r)
{
	int len = (r - l + 1);
	int k = 0;
	while ((1 << k) <= len) ++ k;
	-- k;
	return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int bs(int l, int r, long long aim)
{
	int mid, ret = r + 1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (query(l, mid) <= aim) {
			ret = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ret;
}

int main()
{
	while (~scanf("%d%d", &n, &q)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%lld", &a[i]);
		}
		init();
		for (int i = 1; i <= q; i ++) {
			scanf("%lld%d%d", &v, &l, &r);
			int loc = l;
			while (loc <= r) {
				loc = bs(loc, r, v);
//				cout << loc << " aaaaa" << endl;
				if (loc > r) break;
				v %= a[loc ++];
			}
			printf("%lld\n", v);
		}
		
	}
	return 0;
}
