#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100005;
struct Tree {
	long long sum, tag;
	int l, r;
	long long len() {return (long long)r - (long long)l + 1LL; }
} t[MAX * 4];

void update(int x)
{
	if (t[x].l == t[x].r) return ;
	t[x].sum = t[x*2].sum + t[x*2 + 1].sum;
	return ;
}
void pushdown(int x)
{
	if (!t[x].tag) return ;
	if (t[x].r == t[x].l) return ;
	t[x*2].tag += t[x].tag;
	t[x*2+1].tag += t[x].tag;
	t[x*2].sum += t[x*2].len() * t[x].tag;
	t[x*2+1].sum += t[x*2+1].len() * t[x].tag;
	t[x].tag = 0;
	return ;
}
void build(int x, int l, int r)
{
	t[x].l = l; t[x].r = r; t[x].tag = 0;
	if (l == r) {
		scanf("%lld",&t[x].sum);
		return ;
	}
	int mid = (l+r) >> 1;
	build (x*2,l,mid);
	build (x*2+1,mid+1,r);
	update(x);
	return; 
}
void modify(int x, int l, int r, int v)
{
	if (l <= t[x].l && t[x].r <= r) {
		t[x].tag += v;
		t[x].sum += t[x].len() * v;
		return ;
	}
	int mid = (t[x].l+t[x].r) >> 1;
	pushdown(x);
	if (l <= mid) modify(x*2,l,r,v);
	if (r > mid) modify (x*2+1,l,r,v);
	update(x);
	return ;
}
long long query(int x, int l, int r)
{
	if (l <= t[x].l && t[x].r <= r) {
		return t[x].sum;
	}
	pushdown(x);
	long long ret = 0;
	int mid = (t[x].l + t[x].r) >> 1;
	if (l <= mid) ret += query(x*2,l,r);
	if (r > mid) ret += query(x*2+1,l,r);
	return ret ;
}
int main()
{
	int n,q;
	while (~scanf("%d%d",&n,&q)) {
		build(1,1,n);
		int l,r,v;
		char c;
		for (int i = 1; i <= q; i ++) {
			scanf(" %c%d%d",&c,&l,&r);
			if (c == 'Q') {
				printf("%lld\n",query(1,l,r));
			} else {
				scanf("%d",&v);
				modify(1,l,r,v);
			}
		}
	}
	return 0;
} 
