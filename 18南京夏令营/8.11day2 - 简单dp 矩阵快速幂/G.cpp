#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;
const int MAXN = 1e3 + 10;
const int MAXM = 1e4 + 10;
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXM];
int n, m;
int v[MAXN], w[MAXN];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &v[i]);
	}
	for (int i = 1; i <= m; i ++) {
		dp[0][i] = -INF;
	}
	dp[0][0] = 0;
	int maxx = -1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < w[i]; j ++) {
			dp[i][j] = max(dp[i - 1][j], 0);
		}
		for (int j = m; j >= w[i]; j --) {
			if (dp[i - 1][j] < dp[i - 1][j - w[i]] + v[i]) {
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], 0);
			} else {
				dp[i][j] = max(dp[i - 1][j], 0);
			}
			
		}
	}

	int vol = -1;
	for (int i = 0; i <= m; i ++) {
		if (dp[n][i] > maxx) {
			maxx = dp[n][i];
			vol = i;
		}
	}
	
	stack<int> path;
	int id = n;
	while (true) {
		if (dp[id - 1][vol] == dp[id][vol]) {
			id = id - 1;
		} else {
			path.push(id);
			vol -= w[id];
			-- id;
		}
		if (id == 0) {
			break;
		}
	}

	printf("%d\n", path.size());
	while (!path.empty()) {
		printf("%d ", path.top());
		path.pop();
	}
	return 0;
}
