#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 105;

int mov[2][4] = 
{1,0,-1,0,
0,1,0,-1};
int map[MAX][MAX];
int dp[MAX][MAX];
int n,k;

bool judge(int x, int y)
{
	if (x >= 1 && x <= n && y >= 1 && y<=n) return true;
	else return false;
}
int dfs(int x, int y)
{
	if (dp[x][y]) return dp[x][y];
	int m = 0;
	for (int i = 1; i <= k; i ++) {
		for (int j = 0; j < 4; j ++) {
			int xx = x + mov[0][j] * i;
			int yy = y + mov[1][j] * i;
			if (judge(xx,yy) && map[xx][yy] > map[x][y])
				m = max(m,dfs(xx,yy));
		}
	}
	return dp[x][y] = map[x][y] + m;
}

int main() 
{
	while (~scanf("%d%d",&n,&k), n ^ -1) {
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <=n ; j ++) {
				scanf("%d",&map[i][j]);
			}
		}
		printf("%d\n",dfs(1,1));
	} 
	return 0;
}
