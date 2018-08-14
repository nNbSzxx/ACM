#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 1e3 + 10;
const int ZERO = 1010;
int dp[MAX][MAX];
char s1[MAX], s2[MAX];
int len1, len2;


int main()
{
	scanf(" %s %s", s1 + 1, s2 + 1);
	len1 = strlen(s1 + 1);
	len2 = strlen(s2 + 1);
	for (int i = 1; i < MAX; i ++) {
		dp[0][i] = i;
	}
	for (int j = 1; j < MAX; j ++) {
		dp[j][0] = j;
	}
	for (int i = 1; i <= len1; i ++) {
		for (int j = 1; j <= len2; j ++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}
	/*
	for (int i = 0; i <= len1; i ++) {
		for (int j = 0; j <= len2; j ++) {
			printf("%d ", dp[i][j]);
		}
		puts("");
	}
	printf("%d\n", len2);
	printf("%d\n", dp[len1][len2]);
	*/
	printf("%d\n", dp[len1][len2]);
	return 0;
}
