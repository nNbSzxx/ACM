#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 10;
int n, m, a[MAX], block;
int nt[MAX], lt[MAX], cnt[MAX];

void update(int x, int y)
{
	if (y > n) {
		lt[x] = x;
		cnt[x] = 1;
		nt[x] = n + 1;
	} else if (x / block == y / block) {
		lt[x] = lt[y];
		cnt[x] = cnt[y] + 1;
		nt[x] = nt[y];
	} else {
		lt[x] = x;
		cnt[x] = 1;
		nt[x] = y;
	}
	return ;
}

void set(int id, int v)
{
	a[id] = v;
	for (int i = id; i > 0 && (i / block == id / block); i --) {
		update(i, i + a[i]);
	}
	return ;
}
void find(int x)
{
	int last, ret = 0;
	while (x <= n) {
		ret += cnt[x];
		last = lt[x];
		x = nt[x];
	}
	printf("%d %d\n", last, ret);
	return ;
}
int main()
{
	scanf("%d%d", &n, &m);
	block = ceil(sqrt(n));
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; i --) {
		update(i, i + a[i]);
	}
	int c, x, y;
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &c);
		if (c == 0) {
			scanf("%d%d", &x, &y);
			set(x, y);
		} else {
			scanf("%d", &x);
			find(x);
		}
	}
	return 0;
}
