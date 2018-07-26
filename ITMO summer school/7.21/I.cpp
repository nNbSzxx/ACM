#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 55;
const int MAXT = 105;
const int INF = 0x3f3f3f3f;

int main()
{
    int n;
    cin >> n;
    int p[MAXN], s[MAXN];
    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
    }
    int dp[MAXN][MAXT][2];
    for (int k = 0; k <= 1; k ++)
		for (int i = 0; i <= n; i ++) {
			for (int j = 0; j <= 100; j ++) {
				dp[i][j][k] = -INF;
			}
		}
		
	sort(p + 1, p + 1 + n);
	sort(s + 1, s + 1 + n);

	dp[0][0][0] = dp[0][0][1] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= 100; j ++) {
			dp[i][j][0] = max(dp[i - 1][j][1], dp[i][j][0]);
			for (int k = 1; k <= n; k ++) {
				if (j < p[k]) {
					dp[i][p[k]][0] = max(dp[i][p[k]][0], dp[i - 1][j][1] + 1);
				}
			}
		}
		for (int j = 0; j <= 100; j ++) {
			dp[i][j][1] = max(dp[i][j][0], dp[i][j][1]);
			for (int k = 1; k <= n; k ++) {
				if (j < s[k]) {
					dp[i][s[k]][1] = max(dp[i][s[k]][1], dp[i][j][0] + 1);
				} 
			}
		}
	}
	int ans = -INF;
	for (int i = 0; i <= 100; i ++) {
		ans = max(ans, dp[n][i][1]);
	}
	cout << ans << endl;
	/*
	for (int i = 1; i <= n; i ++) {
		cout << "p1 : " ;
		for (int j = 0; j <= 7; j ++) {
			if (dp[i][j][0] != -INF)
				cout << dp[i][j][0] << " ";
			else
				cout << "Z " ;
		}
		cout << endl;
		cout << "p2 : "  ;
		for (int j = 0; j <= 7; j ++) {
			if (dp[i][j][1] != -INF)
				cout << dp[i][j][1] << " ";
			else
				cout << "Z " ;
		}
		cout << endl;
	}
	*/
	
	
    return 0;
}
