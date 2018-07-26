#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1e6 + 10;
int n, m, k, block;
long long t;
int sum[MAX];
long long cnt[MAX * 2], ans[MAX];
struct query {
	int l, r, id;
} q[MAX];

bool cmp(const query& q1, const query& q2) 
{
	if (q1.l / block < q2.l / block) return true;
	if (q1.l / block == q2.l / block && q1.r < q2.r) return true;
	return false; 
}
void add(int x)
{
	t += cnt[sum[x] ^ k];
	cnt[sum[x]] ++;
	return ;
}
void del(int x)
{
	cnt[sum[x]] --;
	t -= cnt[sum[x] ^ k];
	return;
}
int main()
{
	memset(cnt, 0, sizeof(cnt));
	scanf("%d%d%d", &n, &m, &k);
	block = sqrt(m);
	sum[0] = 0;
	int l, r, a;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a);
		sum[i] = sum[i - 1] ^ a;
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d", &l, &r);
		-- l;
		q[i].l = l;
		q[i].r = r;
		q[i].id = i;
	}
	sort(q + 1, q + m + 1, cmp);
	l = 1;
	r = 0;
	t = 0;
	for (int i = 1; i <= m; i ++) {
		while (q[i].l > l) del(l ++);
		while (q[i].r > r) add(++ r);
		while (q[i].l < l) add(-- l);
		while (q[i].r < r) del(r --);
		ans[q[i].id] = t;
	}
	for (int i = 1; i <= m; i ++) {
		cout << ans[i] << endl;
	}
	return 0;
}


