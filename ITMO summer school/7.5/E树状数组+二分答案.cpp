#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;
int n, m;
int ans[MAX];
long long time[MAX], cnt[MAX];
struct workday {
	int t, id;
} work[MAX];
struct person {
	int d, r, id;
} per[MAX];

bool cmp1 (const workday& w1, const workday& w2)
{
	return w1.t > w2.t;
}
bool cmp2 (const person& p1, const person& p2)
{
	return p1.d > p2.d;
}
inline int lowbit(int x)
{
	return x & (-x);
}
void add(int x, int v, long long treesum[MAX])
{
	while (x <= m) {
		treesum[x] += v;
		x += lowbit(x);
	}
	return ;
}
long long sum(int x, long long treesum[MAX])
{
	long long ret = 0;
	while (x) {
		ret += treesum[x];
		x -= lowbit(x);
	}
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &work[i].t);
		work[i].id = i;
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &per[i].d, &per[i].r);
		per[i].id = i;
	}
	sort(work + 1, work + 1 + m, cmp1);
	sort(per + 1, per + 1 + n, cmp2);
	int p = 1;
	int l, r, tt, mid;
	for (int i = 1; i <= n; i ++) {
		while (p <= m && per[i].d < work[p].t) {
			add(work[p].id, work[p].t, time);
			add(work[p].id, 1, cnt);
			++ p;
		}
		l = 1; r = m; tt = 0;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (sum(mid, time) >= (per[i].d * sum(mid, cnt) + per[i].r)) {
				tt = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans[per[i].id] = tt;
	}
	printf("%d", ans[1]);
	for (int i = 2; i <= n; i ++) {
		printf(" %d", ans[i]);
	}
	puts("");
	return 0;
}
