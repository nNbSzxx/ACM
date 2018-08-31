#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1005;
int ans;
int n,m;
int dp1[MAX][MAX];
int dp2[MAX][MAX];
int dp3[MAX][MAX];
int l[MAX], r[MAX];

void dp(int f[MAX][MAX])
{
	for (int i = 1; i <= n; i ++) {
		l[1] = 1;
		r[m] = m;
		for (int j = 2; j <= m; j ++) {
			int k = j;
			while (k > 1 && f[i][k - 1] >= f[i][j])
				k = l[k - 1];
			l[j] = k;
		}
		
		for (int j = m - 1; j >= 1; j --) {
			int k = j;
			while (k < m && f[i][k + 1] >= f[i][j])
				k = r[k + 1];
			r[j] = k;
		}
		
		for (int j = 1; j <= m; j ++) {
			if (ans < (r[j] - l[j] + 1) * f[i][j])
				ans = (r[j] - l[j] + 1) * f[i][j];
		}
	}
}

int main()
{
	
	while (~scanf("%d%d",&n,&m)) {
		char c;
		ans = 0;
		memset(dp3,0,sizeof(dp3));
		memset(dp2,0,sizeof(dp2));
		memset(dp1,0,sizeof(dp1));
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				scanf(" %c",&c);
				if (c == 'a' || c == 'w' || c == 'y' || c == 'z')
					dp1[i][j] = dp1[i - 1][j] + 1;
				if (c == 'b' || c == 'w' || c == 'x' || c == 'z')
					dp2[i][j] = dp2[i - 1][j] + 1;
				if (c == 'b' || c == 'y' || c == 'x' || c == 'z')
					dp3[i][j] = dp3[i - 1][j] + 1;
			}
		}
		dp(dp1);
		dp(dp2);
		dp(dp3);
		printf("%d\n", ans);
	}
	return 0;
}
