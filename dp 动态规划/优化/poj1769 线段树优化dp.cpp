#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 5e4 + 10;
const int MAXM = 5e5 + 10;
const int INF = 0x3f3f3f3f;
int n, m;
int up[MAXM], down[MAXM];
int dp[MAXN];
int cnt;

struct segtree {
	int minn;
	int l, r;
} tree[MAXN << 2];

void maintain(int x)
{
	if (tree[x].l < tree[x].r) {
		tree[x].minn = min(tree[x << 1].minn, tree[x << 1 | 1].minn);
	}
}

void build(int x, int l, int r)
{
	tree[x].l = l;
	tree[x].r = r;
	if (l == r) {
		if (!cnt) {
			tree[x].minn = 0;
		} else {
			tree[x].minn = INF;
		}
		++ cnt;
		return ;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	maintain(x);
}

int query(int x, int l, int r)
{
	if (l <= tree[x].l && tree[x].r <= r) {
		return tree[x].minn;
	}
	int mid = (tree[x].l + tree[x].r) >> 1;
	if (mid >= r) {
		return query(x << 1, l, r);
	} else if (mid + 1 <= l) {
		return query(x << 1 | 1, l, r);
	} else {
		return min(query(x << 1, l, mid), query(x << 1 | 1, mid + 1, r));
	}
}

void modify(int x, int id, int v)
{
	if (tree[x].l == tree[x].r) {
		tree[x].minn = v;
		return ;
	}
	int mid = (tree[x].l + tree[x].r) >> 1;
	if (mid >= id) {
		modify(x << 1, id, v);
	} else {
		modify(x << 1 | 1, id, v);
	}
	maintain(x);
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d", &up[i], &down[i]);
		}
		cnt = 0;
		build(1, 1, n);
		memset(dp, 0x3f, sizeof dp);
		dp[1] = 0;
		for (int i = 1; i <= m; i ++) {
			int minn = query(1, up[i], down[i]);
			if (dp[down[i]] > minn + 1) {
				dp[down[i]] = minn + 1;
				modify(1, down[i], dp[down[i]]);
			}
		}
		
		printf("%d\n", dp[n]);
	}
	
	return 0;
}


