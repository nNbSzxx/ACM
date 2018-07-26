#include <bits/stdc++.h>
using namespace std;
const int MAX = 60;
int dp[MAX];

int main()
{
	string s;
	while (cin >> s) {
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < s.size(); i ++) {
			dp[i] = 1;
			for (int j = 0; j < i; j ++) {
				if (s[i] > s[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
//		cout << dp[s.size() - 1] << endl;
		int ans = 27;
		for (int i = 0; i < s.size(); i ++) {
			ans = min(ans, 26 - dp[i]);
		} 
		cout << ans << endl;
	}
	
	return 0;
}
