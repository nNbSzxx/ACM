#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010;
const double eps = 1e-6;
int r, c;
double dp[MAX][MAX], p[MAX][MAX][3];

int main()
{
	while (~scanf("%d%d", &r, &c)) {
		for (int i = 1; i <= r; i ++) {
			for (int j = 1; j <= c; j ++) {
				for (int k = 0; k < 3; k ++) {
					scanf("%lf", &p[i][j][k]);
				}
			}
		}
		dp[r][c] = 0;
		for (int i = r; i > 0; i --) {
			for (int j = c; j > 0; j --) {
				if (i == r && j == c || abs(p[i][j][0] - 1) < eps)
					continue;
				dp[i][j] = (dp[i][j + 1] * p[i][j][1]
							+ dp[i + 1][j] * p[i][j][2] + 2)
							/ (1 - p[i][j][0]);
			}
		}
		printf("%.3f\n",dp[1][1]); 
	}
}
