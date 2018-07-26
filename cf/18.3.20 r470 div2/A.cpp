#include <bits/stdc++.h>
using namespace std;
const int MAX = 510;
int n, m;
char s[MAX][MAX];
int step[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
	
int checkSheep(int x, int y)
{
	if (x <= 0 || x > n || y <= 0 || y > m)
		return 1;
	if (s[x][y] == 'W')
		return 0;
	if (s[x][y] == 'S')
		return 1;
	s[x][y] = 'D';
	return 1;
}

int checkWolf(int x, int y)
{
	if (x <= 0 || x > n || y <= 0 || y > m)
		return 1;
	if (s[x][y] == 'S')
		return 0;
	if (s[x][y] == 'W')
		return 1;
	s[x][y] = 'D'; 
	return 1;
}

int main()
{
	scanf("%d %d", &n, &m);
	int flag = 1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			scanf(" %c", &s[i][j]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (s[i][j] == 'S') {
				for (int k = 0; k < 4; k ++) {
					int dx = i + step[k][0];
					int dy = j + step[k][1];
					if (!checkSheep(dx, dy)) {
						flag = 0;
						goto A;
					}
				}
			}
			if (s[i][j] == 'W') {
				for (int k = 0; k < 4; k ++) {
					int dx = i + step[k][0];
					int dy = j + step[k][1];
					if (!checkWolf(dx, dy)) {
						flag = 0;
						goto A;
					}
				}
			}
		}
	}
	A:
	if (flag == 0) {
		puts("No");
	} else {
		puts("Yes");
		for (int i = 1; i <= n; i ++) {
			printf("%s\n", s[i] + 1);
		}
	}
	
	
	return 0;
}
