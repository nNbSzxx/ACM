#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 305;
int map[MAX][MAX];
int n,m;

int main()
{
	while (~scanf("%d%d",&n,&m)) {
		memset(map,0x3f,sizeof(map));
		int a[MAX];
		
		for (int i = 1; i <= m; i ++) {
			int t;
			scanf("%d",&t);
			for (int j = 1; j <= t; j ++) {
				scanf("%d",&a[j]);
				for (int k = 1; k < j; k ++) {
					map[a[j]][a[k] ]= 1;
					map[a[k]][a[j] ]= 1;
				}
			}
		}	
		for (int k = 1; k <= n; k ++) {
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= n; j ++) {
					if (map[i][j] > map[i][k] + map[k][j]) {
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
		for (int i = 1; i <= n; i ++) {
			map[i][i] = 0;
		}
		int sum = 0, m = INF;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				sum += map[i][j];
			}
			if (sum < m) {
				m = sum;
			}
			sum = 0;
		}
		int ans = 1.0 * m * 100 / (n - 1);
		printf("%d\n",ans);
	}
	return 0;
}
