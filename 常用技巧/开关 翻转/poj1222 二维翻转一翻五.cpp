#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int d[4][2] = {
	-1, 0,
	0, 1,
	1, 0,
	0, -1,
};
int a[10][10];
int ans[10][10];

inline int get(int ori[][10], int turn[][10], int x, int y)
{
	return ori[x][y] ^
		   turn[x][y] ^
		   turn[x + d[0][0]][y + d[0][1]] ^
		   turn[x + d[1][0]][y + d[1][1]] ^
		   turn[x + d[2][0]][y + d[2][1]] ^
		   turn[x + d[3][0]][y + d[3][1]];
}

bool check(int ori[][10], int turn[][10])
{
	for (int i = 1; i <= 6; i ++) {
		if (get(ori, turn, 5, i) == 1) {
			return false;
		}
	}	
	return true;
} 

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++ tc) {
		memset(ans, 0, sizeof ans);
		for (int i = 1; i <= 5; i ++) {
			for (int j = 1; j <= 6; j ++) {
				scanf("%d", &a[i][j]);
			}
		}
		int tans[10][10], temp[10][10];
		int cnt = 0x3f3f3f3f;
		
		for (int pat = 0; pat < (1 << 6); pat ++) {
			memset(tans, 0, sizeof tans);
			memcpy(temp, a, sizeof a);
			int tcnt = 0;
			for (int i = 1; i <= 6; i ++) {
				if ((pat >> (6 - i)) & 1 == 1) {
					++ tcnt;
					tans[1][i] = 1;
				}
			}
			for (int i = 2; i <= 5; i ++) {
				for (int j = 1; j <= 6; j ++) {
					if (get(temp, tans, i - 1, j) == 1) {
						++ tcnt;
						tans[i][j] = 1;
					}
				}
			}
			if (check(temp, tans) && tcnt < cnt) {
				cnt = tcnt;
				memcpy(ans, tans, sizeof ans);
			}
		}
		printf("PUZZLE #%d\n", tc);
		for (int i = 1; i <= 5; i ++) {
			for (int j = 1; j <= 6; j ++) {
				printf(j == 6?"%d\n":"%d ", ans[i][j]);
			}
		}
	}
	return 0;
}
