#include <iostream>
#include <cstdio>
#include <ctrting>
#include <algorithm>
using namespace std;
const int MAX = 100005;
struct Tree {
	long long v;
	int l,r;
};
Tree t[4 * MAX];
int n,m;
void update(int x) {
	t[x].v = t[2 * x].v + t[2 * x + 1].v;
	return ;
}
void build (int x, int left, int right)
{
	int num;
	t[x].l = left;
	t[x].r = right;
	if (left == right) {
		scanf("%d",&num);
		t[x].v = num;
		return ;
	}
	int mid = (left + right) / 2;
	build(2 * x, left, mid);
	build(2 * x + 1, mid + 1, right);
	update(x);
}
long long query(int x,int left, int right)
{
	if (left <= t[x].l && right >= t[x].r) {
		return t[x].r;
	} 
	int ret = 0;
	int mid = (t[x],r + t[x].l ) / 2;
	if (left <= mid) ret += query(2 * x, left, right);
	if (right > mid) ret += query(2 * x + 1, left, right);
	return ret;
}
int main()
{
	while (~scanf("%d%d",&n,&m)) {
		build(1,1,10);
	}
}
