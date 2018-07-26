#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 200010;
struct T{
	int begin;
	int end;
	int sum;
};
T t[MAX * 4];

inline Max(int a, int b)
{
	return a > b ? a : b;
}

inline void update(int x)
{
	if (t[x].begin == t[x].end) return;
	t[x].sum = Max(t[x * 2].sum, t[x * 2 + 1].sum);
	return ;
}

void create(int x, int begin, int end)
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
}

void modify(int x, int pos, int v)
{
	if (t[x].begin == t[x].end ) {
		t[x].sum = v;
		return ;
	}
	int mid = (t[x].begin + t[x].end) / 2;
	if (pos > mid) {
		modify(x * 2 + 1, pos, v);
	} else {
		modify(x * 2, pos, v);
	}
	update(x);
}

int query(int x, int begin, int end) 
{
	if (begin <= t[x].begin && end >= t[x].end) {
		return t[x].sum;
	}
	int ret = 0;
	int mid = (t[x].begin + t[x].end) / 2;
	if (mid < end) ret = query(x * 2 + 1, begin, end);
	if (mid >= begin) ret =Max(ret,query(x * 2, begin, end));
	return ret; 
}

int main(int argc, char const *argv[])
{
	int n,m;
	while (~scanf("%d%d",&n,&m)) {
		memset(t,0,sizeof(t));
		create(1,1,n);
		while (m --) {
			char c;
			int a,b;
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
