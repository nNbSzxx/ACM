#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 100005;
long long d[MAX],di[MAX];
int num[MAX];
int n,m;

inline int lowbit(int x)
{
	return x & (-x);
}

void add(int x, long long v)
{
	while (x <= n) {
		d[x] += v;
		x += lowbit(x);
	}
	return ;
}

void addi(int x, long long v)
{
	while (x <= n) {
		di[x] += v;
		x += lowbit(x);
	}
	return ;
}

long long query(int x)
{
	long long ret = 0;
	while (x > 0) {
		ret += d[x];
		x -= lowbit(x);
	}
	return ret;
}

long long queryi(int x)
{
	long long ret = 0;
	while (x > 0) {
		ret += di[x];
		x -= lowbit(x);
	}
	return ret;
}
int main()
{

	while (~scanf("%d%d",&n, &m)) {
		memset(d,0,sizeof(d));
		memset(di,0,sizeof(di));
		num[0] = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&num[i]);
			add (i, num[i] - num[i - 1]);
			addi (i, i * ( num[i] -  num[i - 1]));
		}
		for (int i = 1; i <= m; i ++) {
			char c;
			int a,b,v;
			scanf(" %c",&c);
			if (c == 'C') {
				scanf("%d%d%d",&a,&b,&v);
				add(a, v);
				add(b + 1, -v);
				addi(a,a * v);
				addi(b + 1, -(b + 1) * v);
			}
			if (c == 'Q') {
				scanf("%d%d",&a,&b);
				long long ans;
				ans = (b+1) * query(b) - (a) * query(a - 1) - (queryi(b) - queryi(a - 1));
	
				
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
