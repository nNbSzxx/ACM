#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 105;

int main()
{
	char s1[MAX], s2[MAX];
	int dp[MAX][MAX];
	bool mark2[MAX];
	stack<char> s;
	while (~scanf(" %s %s",s1,s2)) {
		int n = strlen(s1);
		int m = strlen(s2);
		memset(dp,0,sizeof(dp));
		memset(mark2,0,sizeof(mark2));
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}										
			}
		}
		int i = n, j = m;
		while (i > 0 && j > 0) {
			if (s1[i - 1] == s2[j - 1]) {
				s.push(s1[i - 1]);
				i --;
				j --;
			} else {
				if (dp[i-1][j] > dp[i][j-1]) {
					s.push(s1[i-1]);
					i --;
				} else {
					s.push(s2[j-1]);
					j --;
				}
			}
		}
		for (int k = i - 1; k >= 0; k --) {
			s.push(s1[k]);
		}
		for (int k = j - 1; k >= 0; k --) {
			s.push(s2[k]);
		}
		while (!s.empty()) {
			printf("%c",s.top());
			s.pop();
		}
		printf("\n");
	}
}
