/**
 * 归并树，线段树中每个节点保存归并排序时对应区间内排序好的数列，
 * 即保存的是归并排序的过程
 *
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 2e5 + 10;
struct Tree {
	vector<long long> v;
	int l, r;
} t[MAX << 2];
int n, cnta;
long long sum[MAX], tt;

// 归并排序中的合并
void maintain(int x)
{
	int lson = x << 1;
	int rson = x << 1 | 1;
	vector<long long>::iterator i = t[lson].v.begin();
	vector<long long>::iterator j = t[rson].v.begin();
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
	if (l == r) {
		t[x].v.push_back(sum[cnta]);
        ++ cnta;
		return ;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	maintain(x);
}

int query(int x, int l, int r, long long value)
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
    scanf("%d%lld", &n, &tt);
    sum[0] = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &sum[i]);
        sum[i] += sum[i - 1];
    }
    cnta = 0;
    build(1, 1, n);
    //puts("!!!!!!!!!");
    long long ans = 0;
    // 对于答案a[l]，当前区间内有k个数字小于等于a[l]，且a[l]是这样数字中最小的那个
    for (int right = 1; right <= n; right ++) {
        ans += right - query(1, 1, right, sum[right] - tt);
    }
    printf("%lld\n", ans);

	return 0;
}



