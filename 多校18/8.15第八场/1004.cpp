#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 210;
int n, m;
char s[MAX][MAX];

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &m);
		bool swp = false;
		if ((n & 1) == 1) {
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= m / 2; j ++) {
					s[i][j] = '(';
				}
				for (int j = m / 2 + 1; j <= m; j ++) {
					s[i][j] = ')';
				}
			}
		} else if ((m & 1) == 1) {
			for (int j = 1; j <= m; j ++) {
				for (int i = 1; i <= n / 2; i ++ ) {
					s[i][j] = '(';
				}
				for (int i = n / 2 + 1; i <= n; i ++) {
					s[i][j] = ')';
				}
			}
		} else {
			if (n > m) {
				swap(n, m);
				swp = true;
			}
			if (n == 2) {
				for (int j = 1; j <= m; j ++) {
					s[1][j] = '(';
					s[2][j] = ')';
				}
			} else if (n == 4) {
				for (int j = 1; j <= m; j ++) {
					s[1][j] = '(';
					if (j <= m / 2) {
						s[2][j] = ')';
						s[3][j] = '(';
					} else {
						s[2][j] = '(';
						s[3][j] = ')';
					}
					s[4][j] = ')';
				}
			} else {
				for (int j = 1; j <= m; j ++) {
					s[1][j] = '(';
					s[n][j] = ')';
				}
				for (int i = 2; i <= n - 1; i ++) {
					s[i][1] = '(';
					s[i][m] = ')';
				}
				for (int i = 2; i <= n - 1; i ++) {
					for (int j = 2; j <= m - 1; j ++) {
						if (i == 2) {
							if (s[i][j - 1] == '(') {
								s[i][j] = ')';
							} else {
								s[i][j] = '(';
							}
						} else if (s[i - 1][j] == '(') {
							s[i][j] = ')';
						} else {
							s[i][j] = '(';
						}
					}
				}
			}
		}
		if (!swp) {
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= m; j ++) {
					putchar(s[i][j]);
					if (j == m) {
						puts("");
					}
				}
			}
		} else {
			for (int j = 1; j <= m; j ++) {
				for (int i = 1; i <= n; i ++) {
					putchar(s[i][j]);
					if (i == n) {
						puts("");
					}
				}
			}
		}
		
	}
	return 0;
}
