#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 20;
const int U = 0;
const int D = 2;
const int R = 1;
const int L = 3;
const int d[4][2] = {
	-1, 0,
	0, 1,
	1, 0,
	0, -1,
};

int origin[MAX][MAX];
int n, m;

inline int getValue(int ori[][MAX], int stamp[][MAX], int x, int y)
{
	return ori[x][y] ^ stamp[x][y] ^ 
		stamp[x + d[U][0]][y + d[U][1]] ^
		stamp[x + d[R][0]][y + d[R][1]] ^
		stamp[x + d[D][0]][y + d[D][1]] ^
		stamp[x + d[L][0]][y + d[L][1]];
}

bool check(int ori[][MAX], int stamp[][MAX])
{
	for (int i = 1; i <= m; i ++) {
		if (getValue(ori, stamp, n, i) == 1) {
			return false;
		}
	}
	return true;
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		memset(origin, 0, sizeof origin);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				scanf("%d", &origin[i][j]);
			}
		}
		int ans[MAX][MAX];
//		memset(ans, 0, sizeof ans);
		int anscnt = MAX * MAX;
		bool find = false;
		for (int pat = 0; pat < (1 << n); pat ++) {
			int tmp[MAX][MAX];
			memset(tmp, 0, sizeof tmp);
			int cnt = 0;
			for (int i = 1; i <= n; i ++) {
				cnt += (pat >> (n - i)) & 1;
				tmp[1][i] = (pat >> (n - i)) & 1;
			} 
//			int cnt = ((pat >> 3) & 1) + ((pat >> 2) & 1) + ((pat >> 1) & 1) + (pat & 1);
//			tmp[1][1] = (pat >> 3) & 1;
//			tmp[1][2] = (pat >> 2) & 1;
//			tmp[1][3] = (pat >> 1) & 1;
//			tmp[1][4] = pat & 1;
			for (int i = 2; i <= n; i ++) {
				for (int j = 1; j <= m; j ++) {
					if (getValue(origin, tmp, i - 1, j) == 1) {
						++ cnt;
						tmp[i][j] = 1;
					}
				}
			}
			if (check(origin, tmp)) {
				find = true;
				if (cnt < anscnt) {
					anscnt = cnt;
					memcpy(ans, tmp, sizeof ans);
				}
			}
		}
		if (find) {
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= m; j ++) {
					printf(j == m? "%d" : "%d ", ans[i][j]);
				}
				puts("");
			}
		} else {
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}
