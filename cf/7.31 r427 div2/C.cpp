#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 105;
//vector<int> m[MAX][MAX];
//int light[MAX][MAX][10];
//long long sumc[MAX][MAX][10];
//int vis[MAX][MAX];
long long sum[MAX][MAX][10];
long long sumc[MAX][MAX];
long long delta[MAX][MAX][10];

int main()
{
	memset(delta, 0, sizeof(delta));
//	memset(vis, 0, sizeof(vis));
//	memset(light, 0, sizeof(light));
	memset(sum, 0, sizeof(sum));
	memset(sumc, 0, sizeof(sumc));
	int n, q, c;
	scanf("%d%d%d", &n, &q, &c);
	int xx, yy, cc;
	
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d%d", &xx, &yy, &cc);
//			m[xx][yy].push_back(cc);
//			light[xx][yy][cc] ++;
			sum[xx][yy][cc] += 1;
			sumc[xx][yy] += cc;
//			vis[xx][yy] = 1;
			delta[xx][yy][cc] += cc;
	}
	for (int i = 1; i <= 100; i ++) {
		for (int j = 1; j <= 100; j ++) {
			sumc[i][j] += sumc[i - 1][j] + sumc[i][j - 1] - sumc[i - 1][j - 1];
			for (int k = 0; k <= c; k ++) {
				sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i-1][j-1][k];
//				delta[i][j][k] += delta[i][j][k - 1];
			}
		}
	}
	int x1, y1, x2, y2, t;
	long long ans;
	while (q --) {
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
		ans = sumc[x2][y2] - sumc[x2][y1 - 1] - sumc[x1 - 1][y2] + sumc[x1 - 1][y1 - 1];
		t = t % (c + 1);
		if (t != 0)
		for (int i = 0; i <= c; i ++) {
			if (i + t <= c)
				ans += (sum[x2][y2][i]-sum[x2][y1-1][i]-sum[x1-1][y2][i]+sum[x1-1][y1-1][i])* t;					
			else 
				ans += (sum[x2][y2][i]-sum[x2][y1-1][i]-sum[x1-1][y2][i]+sum[x1-1][y1-1][i])*(t - c);
		}
		printf("%lld\n", ans);
	}
	
	return 0;	
} 
