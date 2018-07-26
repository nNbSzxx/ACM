#include <bits/stdc++.h>
using namespace std;
const int MAX = 510;
int n, m, a[MAX], b[MAX];
// dp[i][j] ��ʾa����ǰi����b����ǰj������b[j]�ڹ������������е���󳤶�
// ѹ��һά��LIS��LCS��˼������� 
int dp[MAX];

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		memset(dp, 0, sizeof dp);
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i ++) {
			scanf("%d", &b[i]);
		}
		int ans = -1;
		for (int i = 1; i <= n; i ++) {
			int maxx = 0;
			for (int j = 1; j <= m; j ++) {
				if (a[i] == b[j]) {
					dp[j] = max(dp[j], maxx + 1);
				}
				if (b[j] < a[i]) {
					maxx = max(maxx, dp[j]);
				}
				ans = max(ans, dp[j]);
			}
		}
		printf("%d\n", ans);
		if (tc != 0)
			puts(""); 
	}
	return 0;
}
