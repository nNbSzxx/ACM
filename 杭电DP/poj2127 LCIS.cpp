#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 510;
int dp[MAX][MAX], path[MAX][MAX];

int main()
{
	int n, m, a[MAX], b[MAX];
	while (cin >> n) {
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		cin >> m;
		for (int i = 1; i <= m; i ++) {
			cin >> b[i];
		}
		
		memset(dp, 0, sizeof(dp));
		memset(path, -1, sizeof(path));
		int lastj = -1, ans = 0;
		for (int i = 1; i <= n; i ++ ) {
			int maxl = 0, last = -1;
			for (int j = 1; j <= m; j ++) {
				dp[i][j] = dp[i - 1][j];
	//			path[i][j] = j;
				if (b[j] < a[i] && maxl < dp[i - 1][j]) {
					maxl = dp[i - 1][j];
					last = j;
				} else if (b[j] == a[i]) {
					dp[i][j] = maxl + 1;
					path[i][j] = last;
					if (dp[i][j] > ans) {
						ans = dp[i][j];
						lastj = j;
					}
				}
			}
		}
		cout << ans << endl;
		stack<int> s;
		int i = n, j = lastj;
		while (j > 0) {
			s.push(b[j]);
			while (b[j] != a[i]) {
				-- i;
			}
			j = path[i][j];
			-- i;
//			if (i < 0) break;
		}
		if (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		while (!s.empty()) {
			cout << " " << s.top();
			s.pop();
		}
		cout << endl;
	}
	
	return 0;
}
