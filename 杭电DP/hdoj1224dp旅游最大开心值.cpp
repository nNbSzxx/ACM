#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 110;

int main()
{
	int map[MAX][MAX];
	int dp[MAX];
	int path[MAX];
	int v[MAX];
	int n,m;
	int t;
	int tc = 1;
	scanf("%d",&t);
	while (t --) {
		if (tc > 1) printf("\n");
		scanf("%d",&n);
		memset(path,0,sizeof(path));
		memset(map,0,sizeof(map));
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&v[i]);
		}
		v[n + 1] = 0;
		scanf("%d",&m);
		for (int i = 1; i <= m; i ++) {
			int a,b;
			scanf("%d%d",&a,&b);
			map[a][b] = 1;
		}
		
		for (int i = 1; i <= n + 1; i ++) {
			for (int j = 1; j < i; j ++) {
				if (map[j][i] && dp[i] < dp[j] + v[i]) {
					dp[i] = dp[j] + v[i];
					path[i] = j;
				}
			}
		}
		printf("CASE %d#\n",tc ++);
		printf("points : %d\n",dp[n+1]);
		printf("circuit : ");
		int i = path[n + 1];
		stack<int> s;
		while (i) {
			s.push(i);
			i = path[i];
		}  
		while (!s.empty()) {
			printf("%d->",s.top());
			s.pop();
		}
		printf("1");
		printf("\n");
	}
	return 0;
}
