#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 10;
const int MAXH = 20;

struct Tree {
	int l, r;
	int xr1, xl2;
	int inv, invl, invr;
	int d;
} t[MAX << 2];
int n, m, cnta;
int sorted[MAXH][MAX];
int a[MAX];

void maintain(int x, int d)
{
    int lson = x << 1;
    int rson = x << 1 | 1;
	int i = t[lson].xr1;
	int j = t[rson].xl2;
	int mid = t[lson].r;
	int k = i;
	while (i != mid + 1 && j != r + 1) {
		if (a[d + 1][i] < a[d + 1][j]) {
			a[d][k ++] = a[d + 1][i];
			++ i;
		} else {
			a[d][k ++] = a[d + 1][j];
			t[x].inv += mid - i + 1;
			++ j;
		}
	}
	while (i != mid + 1) {
		a[d][k ++] = a[d + 1][i];
		++ i;
	}
	while (j != r + 1) {
		a[d][k ++] = a[d + 1][j];
		++ j;
	}
	for (int i = t[x].l; i < t[lson].xl2; i ++) {
        a[d][i] = a[d + 1][i];
	}
	for (int i = t[rson].xr1 + 1; i <= t[x].r; i ++) {
        a[d][i] = a[d + 1][i];
	}
}

void build(int x, int l, int r, int d)
{
	t[x].l = l;
	t[x].r = r;
	t[x].d = d;
	t[x].xl2 = l;
	t[x].xr1 = r;
	t[x].inv = t[x].invl = t[x].invr = 0;
	if (l == r) {
		sorted[d][l] = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid, d + 1);
	build(x << 1 | 1, mid + 1, r, d + 1);

	maintain(x, d);
}

int query(int x, int l, int r, int value)
{
	int ret = 0;
	if (l <= t[x].l && t[x].r <= r) {
		ret = upper_bound(t[x].v.begin(), t[x].v.end(), value) - t[x].v.begin();
		return ret;
	}
	int mid = (t[x].l + t[x].r) >> 1;
	if (r <= mid) {
		ret = query(x << 1, l, r, value);
	} else if (l >= mid + 1) {
		ret = query(x << 1 | 1, l, r, value);
	} else {
		ret = query(x << 1, l, mid, value);
		ret += query(x << 1 | 1, mid + 1, r, value);
	}
	return ret;
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		cnta = 0;
		build(1, 1, n, 1);
		sort(a + 1, a + 1 + n);
		// 对于答案a[l]，当前区间内有k个数字小于等于a[l]，且a[l]是这样数字中最小的那个
		while (m --) {
			int left, right, k;
			scanf("%d%d%d", &left, &right, &k);
			int l = 1, r = n, mid;
			while (l <= r) {
				mid = (l + r) >> 1;
				int num = query(1, left, right, a[mid]);
				if (num <= k - 1) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			printf("%d\n", a[l]);
		}
	}
	return 0;
}



