#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 15;

int n;
char s[MAX + 3][110];
int cost[MAX + 3][MAX + 3];
int eli[MAX + 3];
int dp[(1 << MAX) + 10][MAX + 3];
int path[(1 << MAX) + 10][MAX + 3];
int cmp[MAX + 3][MAX + 3][MAX + 3];
int loc[MAX + 3][MAX + 3];
int fullmask;

bool eql(char *s1, char *e1, char *s2, char *e2)
{
	while (s1 != e1) {
		if (*s1 != *s2) {
			return false;
		}
		++ s1;
		++ s2;
	}
	return true;
}

void init()
{
	memset(eli, 0, sizeof eli);
	fullmask = (1 << n) - 1;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < i; j ++) {
			if (strstr(s[i], s[j]) != NULL) {
				eli[j] = 1;
				fullmask &= ~ (1 << j);
			} else if (strstr(s[j], s[i]) != NULL) {
				eli[i] = 1;
				fullmask &= ~ (1 << i);
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		if (eli[i]) {
			continue;
		}
		for (int j = 0; j < n; j ++) {
			if (eli[j] || i == j) {
				continue;
			}
			int len1 = strlen(s[i]);
			int lim = min((int)strlen(s[j]), len1);
			cost[i][j] = len1;
			loc[i][j] = 0;
			for (int k = 1; k <= lim; k ++) {
				if (eql(s[i] + len1 - k, s[i] + len1, s[j], s[j] + k)) {
					cost[i][j] = len1 - k;
					loc[i][j] = k;
				}
			}
//			cmp[i][j] = strcmp(s[i], s[j]);
		}
	}
	for (int k = 0; k < n; k ++) {
		if (eli[k]) continue;
		for (int i = 0; i < n; i ++) {
			if (eli[i] || i == k) continue;
			for (int j = 0; j < i; j ++) {
				if (eli[j] || j == k) continue;
				cmp[k][i][j] = strcmp(s[i] + loc[k][i], s[j] + loc[k][j]);
				cmp[k][j][i] = - cmp[k][i][j];
			}
		}
	}
}

int main()
{
	int t, tc = 1;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			scanf(" %s", s[i]);
		}
		init();
		memset(dp, 0x3f, sizeof dp);
		memset(path, -1, sizeof path);
		for (int i = 0; i < n; i ++) {
			if (!eli[i])
				dp[(1 << i)][i] = strlen(s[i]);
		}
		for (int mask = 1; mask < (1 << n); ++ mask) {
			for (int i = 0; i < n; i ++) {
				if (eli[i] || dp[mask][i] == 0x3f3f3f3f) continue;
				if (((1 << i) & mask) != 0) {
					for (int j = 0; j < n; j ++) {
						if (eli[j]) continue;
						if (((1 << j) & mask) == 0) {
							if (dp[mask | (1 << j)][j] > dp[mask][i] + cost[j][i]) {
								dp[mask | (1 << j)][j] = dp[mask][i] + cost[j][i];
								path[mask | (1 << j)][j] = i;	
							} else if (dp[mask | (1 << j)][j] == dp[mask][i] + cost[j][i] &&
									   cmp[j][i][path[mask | (1 << j)][j]] < 0) {
								path[mask | (1 << j)][j] = i;		   	
							}
						}
					}
				}
			}
		}
		
		int id = -1;
		int minn = 0x3f3f3f3f;
		for (int i = 0; i < n; i ++) {
			if (dp[fullmask][i] < minn) {
				minn = dp[fullmask][i];
				id = i;
			} else if (dp[fullmask][i] == minn && id != -1) {
				if (strcmp(s[i], s[id]) < 0) {
					id = i;
				}
			}
		}
//		printf("%d\n", id);
		printf("Scenario #%d:\n", tc ++);
		int lastid = n;
		int mask = fullmask;
		loc[n][id] = 0;
		while (id != -1) {
//			printf("%d %d\n", id, dp[mask][id]);
			printf("%s", s[id] + loc[lastid][id]);
			lastid = id;
			id = path[mask][id];
			mask ^= (1 << lastid);
		}
		puts("\n");
//		printf("%d\n", dp[fullmask & ~(1 << 8)][13]);
//		printf("%d\n", dp[fullmask & ~(1 << 8)][13] + cost[8][13]);
//		printf("%d\n", cmp[13][4]);
//		printf("%d\n", cmp[4][13]);
//		printf("%d\n", minn);
//		printf("%d %d\n", cost[0][1], cost[1][0]);
	}
	
	return 0;
}







