#include <bits/stdc++.h>
using namespace std;
const int MAX = 110;
int dp[MAX][2010], n, path[MAX][2010];
struct item {
	int t, d, p, id;
} it[MAX];

bool cmp(const item& i1, const item& i2)
{
	return i1.d < i2.d;
}

int main()
{
	scanf("%d", &n);
	int maxx = -1;
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d%d", &it[i].t, &it[i].d, &it[i].p);
		it[i].id = i;
		maxx = max(it[i].d, maxx);
	}
	sort(it + 1, it + 1 + n, cmp);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= maxx; j ++) {
			dp[i][j] = dp[i - 1][j];
//			if (it[i].p <= it[i].d) continue;
			if (j >= it[i].t && j < it[i].d)
				if (dp[i][j] < dp[i - 1][j - it[i].t] + it[i].p) {
					dp[i][j] = dp[i - 1][j - it[i].t] + it[i].p;
					path[i][j] = i;
				}
		}
	}
	int ans = -1, pos;
	for (int j = 1; j <= maxx; j ++) {
		if (ans < dp[n][j]) ans = dp[n][j], pos = j;
	}
	printf("%d\n", ans);
	stack<int> ansit;
	int i = n, j = pos;
	while (i && j) {
		if (path[i][j]) {
			ansit.push(it[path[i][j]].id);
			j -= it[path[i][j]].t;
		}
		-- i;
	}
	printf("%d\n", ansit.size());
	while (!ansit.empty()) {
		printf("%d ", ansit.top());
		ansit.pop();
	}
	puts("");
}
