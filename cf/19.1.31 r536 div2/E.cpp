#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 210;
const int S = 0;
const int T = 1;

struct Job {
	int s, t, d, w;
} job[MAXN];

set<int> s;
long long dp[MAXN][MAXM];

struct event {
	int p, id, t;
} e[MAXN << 1];

bool cmp(const event& e1, const event& e2)
{
	return e1.p < e2.p;
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i ++) {
		scanf("%d%d%d%d", &job[i].s, &job[i].t, &job[i].d, &job[i].w);
		-- job[i].s;
		e[i * 2 - 1].p = job[i].s;
		e[i * 2 - 1].t = S;
		e[i * 2 - 1].id = i;
		e[i << 1].p = job[i].t;
		e[i << 1].t = T;
		e[i << 1].id = i;
	}
	sort(e + 1, e + 2 * k + 1, cmp);
	int cur = 2 * k;
	for (int i = 0; i <= m; i ++)
		dp[n + 1][i] = 0;
	int mc = 0, md = -1;
	for (int i = n; i >= 1; i --) {
		//cout << "i : " << i << endl;
		bool change = false;
		while (1) {
			//cout << e[cur].p << endl;
			if (e[cur].p < i) {
				break;
			} else if (e[cur].p == i) {
				if (e[cur].t == T) {
					s.insert(e[cur].id);
				} else {
					s.erase(e[cur].id);
				}
				change = true;
			}
			-- cur;
		}
		if (change) {
			int maxcoin = 0;
			int maxd = -1;
			for (auto it = s.begin(); it != s.end(); it ++) {
				int id = *it;
				if (job[id].w > maxcoin) {
					maxcoin = job[id].w;
					maxd = job[id].d;
				} else if (job[id].w == maxcoin && job[id].d > maxd) {
					maxd = job[id].d;
				}
			}
			mc = maxcoin;
			md = maxd;
		}
		for (int j = 0; j <= m; j ++) {
			dp[i][j] = 0;
			if (md != -1) {
				dp[i][j] = dp[md + 1][j] + mc;
			}
			if (j != 0) {
				dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
			}
		}
		
		
	}
	long long ans = dp[1][0];
	for (int i = 1; i <= m; i ++) {
		ans = min(ans, dp[1][i]);
	}
	printf("%lld\n", ans);
	return 0;
}
