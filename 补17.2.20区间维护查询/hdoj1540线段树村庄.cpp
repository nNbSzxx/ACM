#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 50005;
struct Tree {
	int left, right;
	int lmax, rmax;
	int len;
} t[4 * MAX];
int n,m;
stack<int> s;
void update(int x)
{
	if (t[x].left == t[x].right) return ;
	t[x].len = t[x*2].len + t[x*2+1].len;
//	t[x].left = t[x*2].left; t[x].right = t[x*2+1].right;
	t[x].lmax = t[x*2].lmax;
	if (t[x*2].right - t[x*2].left + 1 == t[x*2].len) t[x].lmax += t[x*2+1].lmax;
	t[x].rmax = t[x*2+1].rmax;
	if (t[x*2+1].right - t[x*2+1].left + 1 == t[x*2+1].len) t[x].rmax += t[x*2].rmax;
	return ;
}

void build (int x, int l, int r)
{
	t[x].right = r; t[x].left = l;
	if (l == r) {
		t[x].lmax = t[x].len = t[x].rmax = 1;
		return ;
	}
	int mid = (l+r) >> 1;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	update(x);
}

void modify(int x, int cor, int tag)
{
	if (t[x].right == t[x].left ) {
		if (tag) {
			t[x].len = 0;
			t[x].lmax = t[x].rmax = 0;
		} else {
			t[x].lmax = t[x].rmax = t[x].len = 1;
		}
		return ;
	}
	int mid = (t[x].left + t[x].right) >> 1;
	if (cor <= mid) {
		modify(x*2,cor,tag);
	} else {
		modify(x*2+1,cor,tag);
	}
	update(x);
}

int query(int x, int q)
{
	if (t[x].len == t[x].right-t[x].left+1) {
		return t[x].len;
	}
	if (t[x].left == t[x].right) {
		return t[x].len;
	}
	if (t[x].len == 0) {
		return 0;
	}
	int mid = (t[x].left + t[x].right) >> 1;
	int ret = 0;
	if (q <= mid) {
		ret = query(x*2,q);
		if (q >= t[x*2].right - t[x*2].rmax + 1) ret += query(x*2+1,mid+1);
	} else {
		ret = query(x*2+1,q);
		if (q <= t[x*2+1].left + t[x*2+1].lmax - 1) ret += query(x*2, mid);
	}
	return ret;
}

int main()
{
	while (~scanf("%d%d",&n,&m) ) {
		memset(t,0,sizeof(t));
		while (!s.empty()) s.pop();
		build(1,1,n);
		char c; int k;
		for (int i = 1; i <= m; i ++) {
			scanf(" %c",&c);
			if (c == 'D') {
				scanf("%d",&k);
				s.push(k);
				modify(1,k,1);
			}
			if (c == 'Q') {
				scanf("%d",&k);
				printf("%d\n",query(1,k));
			}
			if (c == 'R') {
				int now = s.top(); s.pop();
				modify(1,now,0);
			}
		}
	}
	return 0;
} 



