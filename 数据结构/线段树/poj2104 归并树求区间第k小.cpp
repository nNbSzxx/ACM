#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 10;
struct Tree {
	vector<int> v;
	int l, r;
} t[MAX << 2];
int n, m, cnta;
int a[MAX];

void maintain(int x)
{
	int lson = x << 1;
	int rson = x << 1 | 1;
	vector<int>::iterator i = t[lson].v.begin();
	vector<int>::iterator j = t[rson].v.begin();
	while (i != t[lson].v.end() && j != t[rson].v.end()) {
		if (*i < *j) {
			t[x].v.push_back(*i);
			++ i;
		} else {
			t[x].v.push_back(*j);
			++ j;
		}
	}
	while (i != t[lson].v.end()) {
		t[x].v.push_back(*i);
		++ i;
	}
	while (j != t[rson].v.end()) {
		t[x].v.push_back(*j);
		++ j;
	}
}

void build(int x, int l, int r)
{
	t[x].l = l;
	t[x].r = r;
	t[x].v.clear();
	if (l == r) {
		scanf("%d", &a[++ cnta]);
		t[x].v.push_back(a[cnta]);
		return ;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	maintain(x);
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
		build(1, 1, n);
		sort(a + 1, a + 1 + n);
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


