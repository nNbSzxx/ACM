#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
// 记录区间最小值 
struct Tree {
	int l, r, v;
	int dec; // lazy tag
	int id; // 叶子节点在数组中的位置 
} t[MAX << 4];
int treesum[MAX];
int n, m, cnt;
int b[MAX];

void init()
{
	cnt = 1;
	memset(treesum, 0, sizeof treesum);
}

inline int lowbit(int x)
{
	return x & (-x);
}

void modifyArray(int x, int del)
{
	for (int i = x; i <= n; i += lowbit(i)) {
		treesum[i] += del;
	}
}

int queryArray(int x)
{
	int ret = 0;
	for (int i = x; i; i -= lowbit(i)) {
		ret += treesum[i];
	}
	return ret;
}

void maintain(int x)
{
	t[x].v = min(t[x * 2].v, t[x * 2 + 1].v);
}

void build(int x, int l, int r)
{
	t[x].l = l;
	t[x].r = r;
	t[x].dec = 0;
	if (l == r) {
		t[x].id = cnt;
		t[x].v = b[cnt ++];
		return ;
	}
	int mid = (l + r) >> 1;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	maintain(x);
}

void pushdown(int x)
{
	if (t[x].dec) {
		t[x * 2].v += t[x].dec;
		t[x * 2].dec += t[x].dec;
		t[x * 2 + 1].v += t[x].dec;
		t[x * 2 + 1].dec += t[x].dec;
		t[x].dec = 0;
	}
}

void modify(int x, int l, int r, int del)
{
	if (l <= t[x].l && t[x].r <= r) {
		t[x].v += del;
		t[x].dec += del;
		return ;
	}
	pushdown(x);
	int mid = (t[x].l + t[x].r) >> 1;
	if (r <= mid) {
		modify(x * 2, l, r, del);
	} else if (l >= mid + 1) {
		modify(x * 2 + 1, l, r, del);
	} else {
		modify(x * 2, l, mid, del);
		modify(x * 2 + 1, mid + 1, r, del);
	}
	maintain(x);
}

// 特殊的query，查到0以及0的位置，也就是有0则强行查到叶子节点 
void query(int x, int l, int r)
{
	if (t[x].l == t[x].r) {
		modifyArray(t[x].id, 1);
		t[x].v = b[t[x].id];
		return ;
	}
	
	pushdown(x);
	int mid = (t[x].l + t[x].r) >> 1;
	if (t[x * 2].v == 0)
		query(x * 2, l, mid);
	if (t[x * 2 + 1].v == 0)
		query(x * 2 + 1, mid + 1, r);
	maintain(x);
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		init();
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &b[i]);
		}
		build(1, 1, n);
		char s[11];
		int x, y;
		while (m --) {
			scanf(" %s%d%d", s, &x, &y);
			if (s[0] == 'a') {
				modify(1, x, y, -1);
				query(1, 1, n);
			} else {
				printf("%d\n", queryArray(y) - queryArray(x - 1));
			}
		}
	}
	return 0;
}
