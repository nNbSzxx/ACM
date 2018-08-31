#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 1010;
double dp[MAX][MAX];
int n, s;

int main()
{
	while (~scanf("%d%d", &n, &s)) {
		dp[n][s] = 0;
		for (int i = n; i >= 0; i --) {
			for (int j = s; j >= 0; j --) {
				if (i == n && j == s) continue;
				dp[i][j] = (dp[i + 1][j + 1] * (n - i) * (s - j) / (n * s) 
					 		+ dp[i + 1][j] * (n - i) * j / (n * s) 
					 		+ dp[i][j + 1] * (i) * (s - j) / (n * s)
							+ 1)
					 		/ (1 - 1.0 * i * j / (n * s));
			}
		}
		printf("%.4f\n", dp[0][0]);
	}
	return 0;
}
