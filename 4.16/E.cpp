#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 4010;
struct N {
	int x, id;
} a[MAX], b[MAX];
long long dp[2][MAX];
int path[MAX][MAX];
int ans[MAX];

bool cmp(N& n1, N &n2)
{
	return n1.x < n2.x;
}
void print(int x, int y)
{
	if (x == 0) return;
	ans[a[x].id] = b[y].id;
	if (path[x][y]) {
		print(x - 1, y - 1);
	} else {
		print(x - 1, y);
	}
}
int main()
{
	int n,m;
	while (~scanf("%d",&n) ) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i].x);
			a[i].id = i;
		}	
		scanf("%d",&m);
		for (int i = 1; i <= m; i ++) {
			scanf("%d",&b[i].x);
			b[i].id = i;
		}
		sort (a + 1, a + n + 1, cmp);
		sort (b + 1, b + m + 1, cmp);
		int ori = 1, aim = 0;
		memset(dp, 0x3f, sizeof(dp));
		memset(path, 0, sizeof(path));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i ++) {
			swap(ori, aim);
			for (int j = 1; j <= m && j <= i; j ++) {
				if (j == i) {
					dp[aim][j] = dp[ori][j - 1] + abs(a[i].x - b[j].x);
					path[i][j] = 1;
					continue;
				}
				if (j == 1) {
					dp[aim][j] = dp[ori][j] + abs(a[i].x - b[j].x);
					path[i][j] = 0;
					continue;
				} 
				if (dp[ori][j-1] > dp[ori][j]) {
					dp[aim][j] = dp[ori][j] + abs(a[i].x - b[j].x);
					path[i][j] = 0;
				} else {
					dp[aim][j] = dp[ori][j - 1] + abs(a[i].x - b[j].x);
					path[i][j] = 1;
				}
				
			}
		}
		printf("%lld\n",dp[aim][m]);
		print(n, m);
		printf("%d",ans[1]);
		for (int i = 2; i <= n; i ++) {
			printf(" %d", ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}


//for (int i = 1; i <= n; i ++) {
//	for (int j = 1; j <= m && j <= n; j ++) {
//		dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + abs(da[i] - db[j]);
//	}
//}
