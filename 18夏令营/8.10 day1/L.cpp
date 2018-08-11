#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;
int cnt[MAX];
int n, m;

struct P {
	int s, id;
} p[MAX];

bool cmp(const P& p1, const P& p2)
{
	return p1.s < p2.s;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &p[i].s);
		p[i].id = i;
	}
	int u, v;
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d", &u, &v);
		if (p[u].s != p[v].s) {
			if (p[u].s > p[v].s) {
				cnt[u] ++;
			} else {
				cnt[v] ++;
			}
		}
	}
	sort(p + 1, p + 1 + n, cmp);
	int ans[MAX];
	int smid = 0;
	ans[p[1].id] = 0;
	for (int i = 2; i <= n; i ++) {
		if (p[i].s != p[i - 1].s) {
			smid = i - 1;
		}
		ans[p[i].id] = smid - cnt[p[i].id];
	}
	for (int i = 1; i <= n; i ++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
