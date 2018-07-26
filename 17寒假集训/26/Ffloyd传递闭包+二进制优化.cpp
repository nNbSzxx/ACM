#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
const int MAX = 1005;
using namespace std;
//int map[MAX][MAX];

bitset<MAX> map[MAX];
int visit[MAX];

int main()
{
	int t,n;
	scanf("%d",&t);
	int tc = 1;
	while (t --) {
		scanf("%d",&n);
		memset(visit,0,sizeof(visit));
		memset(map,0,sizeof(map));
		
		for (int i = 1; i <= n; i ++) {
			int m;
			scanf("%d",&m);
			map[i][i] = 1;
			for (int j = 1; j <=m ; j ++) {
				int v;
				scanf("%d",&v);
				map[i][v] = 1;
			}
		}
		
		for (int k = 1; k <= n; k ++) {
			for (int i = 1; i <= n; i ++) {
				if (map[i][k] ) {
					map[i] |= map[k];
				}
			}
		}
		
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (map[i][j]) {
					visit[j] ++;
				}
			}
		}
		
		double ans = 0.0;
		for (int i = 1; i <= n; i ++) {
			ans += 1.0 / visit[i];
		}
		printf("Case #%d: %.5f\n",tc++,ans);
	}
}
