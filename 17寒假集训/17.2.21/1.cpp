#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 200005;

struct T{
	int begin,end;
	int sum;
};

T t[MAX*4];

inline int Max(int a,int b)
{
	return a > b ? a : b;
}

void update(int x)
{
	if (t[x].begin == t[x].end) {
		return ;
	}
	t[x].sum = Max(t[x * 2].sum, t[x * 2 + 1].sum);
	return ;
}

void create(int x,int begin,int end)
{
	t[x].begin = begin;
	t[x].end = end;
	if (begin == end) {
		scanf("%d",&t[x].sum);
		return ;
	}
	int mid = (begin + end) / 2;
	create(x * 2, begin, mid);
	create(x * 2 + 1, mid + 1, end);
	update(x);
	return ;
}

void modify(int x, int pos, int v)
{
	if (t[x].begin == t[x].end) {
		t[x].sum = v;
		return ;
	}
	int mid = (t[x].begin + t[x].end) / 2;
	if (pos > mid) modify(x * 2 + 1, pos, v);
	else modify(x * 2, pos, v);
	update(x);
	return;
}

int query(int x, int begin, int end)
{
	if (begin <= t[x].begin && end >= t[x].end) {
		return t[x].sum;
	}
	int mid = (t[x].begin + t[x].end) / 2;
	int ret = 0;
	if (mid >= begin) ret = query(x * 2, begin, end);
	if (mid < end) ret = Max(ret, query(x * 2 + 1, begin, end));
	return ret; 
}

int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m)) {
		memset(t,0,sizeof(t));
		create(1,1,n);
		char c;
		int a,b;
		for (int i = 0; i < m; i ++) {
			scanf(" %c%d%d",&c,&a,&b);
			if (c == 'Q') {
				printf("%d\n",query(1,a,b));
			}
			if (c == 'U') {
				modify(1,a,b);
			}
		}
	}
	
	return 0;
}
