#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
struct SegTree {
	int l, r, v, tag, len;
} tree[MAX << 2];
vector<int> e[MAX];
int n, q, ini[MAX], in[MAX], out[MAX], dnf[MAX], ts = 0;

void dfs(int x)
{
	in[x] = ++ ts;
	dnf[ts] = x;
	for (int i = 0; i < e[x].size(); i ++) {
		dfs(e[x][i]);
	}
	out[x] = ts;
	return ;
}

inline void update(int x)
{
	if (tree[x].l != tree[x].r)
		tree[x].v = tree[x << 1].v + tree[x << 1 | 1].v;
	return ;
}

inline void pushdown(int x)
{
	if (tree[x].tag) {
		tree[x].tag = 0;
		tree[x << 1].v = tree[x << 1].len - tree[x << 1].v;
		tree[x << 1 | 1].v = tree[x << 1 | 1].len - tree[x << 1 | 1].v;
		tree[x << 1].tag ^= 1;
		tree[x << 1 | 1].tag ^= 1; 
	}
	return ;
}

void build(int x, int l, int r)
{
	tree[x].l = l;
	tree[x].r = r;
	tree[x].tag = 0;
	tree[x].len = r - l + 1;
	if (l == r) {
		tree[x].v = ini[dnf[l]];
		return ;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	update(x);
	return ;
}

void modify(int x, int l, int r)
{
	if (l <= tree[x].l && tree[x].r <= r) {
		tree[x].v = tree[x].len - tree[x].v;
		tree[x].tag ^= 1;
		return ;
	}
	pushdown(x);
	int mid = (tree[x].l + tree[x].r) >> 1;
	if (mid >= l)
		modify(x << 1, l, r);
	if (mid < r)
		modify(x << 1 | 1, l, r);
	update(x);
	return ;
}

int query(int x, int l, int r)
{
	if (l <= tree[x].l && tree[x].r <= r) {
		return tree[x].v;
	}
	pushdown(x);
	int ret = 0;
	int mid = (tree[x].l + tree[x].r) >> 1;
	if (mid >= l)
		ret += query(x << 1, l, r);
	if (mid < r)
		ret += query(x << 1 | 1, l, r);
	return ret;
}

int main()
{
	scanf("%d", &n);
	int f;
	for (int i = 2; i <= n; i ++) {
		scanf("%d", &f);
		e[f].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &ini[i]);
	}
	build(1, 1, n);
	scanf("%d", &q);
	char s[10]; int x;
	while (q --) {
		scanf(" %s %d", s, &x);
		if (!strcmp(s, "get")) {
			printf("%d\n", query(1, in[x], out[x]));
		} else {
			modify(1, in[x], out[x]);
		}
	}
	return 0;
}
