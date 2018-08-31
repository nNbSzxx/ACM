#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 86405;
const long long INF = 5e9 + 10LL;

struct segtree {
	long long minn;
	int l, r;
} tree[MAXM << 2];
struct cow {
	int b, e, cost;
} c[MAXN];
int n, m, e;
int iszero;
long long dp[MAXM];

bool cmp(const cow& c1, const cow& c2)
{
	if (c1.b != c2.b) {
		return c1.b < c2.b;
	} else {
		return c1.e < c2.e;
	}
}

void maintain(int x)
{
	if (tree[x].l != tree[x].r) {
		tree[x].minn = min(tree[x << 1].minn, tree[x << 1 | 1].minn);
	}
}

void build(int x, int l, int r)
{
	tree[x].l = l;
	tree[x].r = r;
	if (l == r) {
		if (iszero) {
			tree[x].minn = 0;
			iszero = 0;
		} else {
			tree[x].minn = INF;
		}
		return ;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	maintain(x);
}

void modify(int x, int id, int v)
{
	if (tree[x].l == tree[x].r) {
		tree[x].minn = v;
		return ;
	}
	int mid = (tree[x].l + tree[x].r) >> 1;
	if (id <= mid) {
		modify(x << 1, id, v);
	} else {
		modify(x << 1 | 1, id, v);
	}
	maintain(x);
}

long long query(int x, int l, int r)
{
	if (l <= tree[x].l && tree[x].r <= r) {
		return tree[x].minn;
	}
	int mid = (tree[x].l + tree[x].r) >> 1;
	long long ret;
	if (r <= mid) {
		ret = query(x << 1, l, r);
	} else if (l >= mid + 1) {
		ret = query(x << 1 | 1, l, r);
	} else {
		ret = min(query(x << 1, l, mid), query(x << 1 | 1, mid + 1, r));
	}
	return ret;
} 

int main()
{
	while (~scanf("%d%d%d", &n, &m, &e)) {
		int del = 1 - m;
		m += del; // m == 1
		e += del; // range : 1 - e
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d%d", &c[i].b, &c[i].e, &c[i].cost);
			c[i].b += del;
			c[i].e += del;
		}
		sort(c + 1, c + 1 + n, cmp);
		iszero = 1;
		build(1, 0, e);
		dp[0] = 0;
		for (int i = 1; i <= e; i ++) {
			dp[i] = INF;
		}
		for (int i = 1; i <= n; i ++) {
			int beg = c[i].b;
			int ed = c[i].e;
			long long newcost = query(1, beg - 1, ed) + c[i].cost;
			if (dp[ed] > newcost) {
				dp[ed] = newcost;
				modify(1, ed, newcost);
			}
		}
		if (dp[e] == INF) {
			puts("-1");
		} else {
			printf("%lld\n", dp[e]);
		}
	}
	
	
	return 0;
}



