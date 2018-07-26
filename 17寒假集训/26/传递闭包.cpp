#include <iostream>
#include <cstdio>
#include <cstring>
const int MAX = 10005;
using namespace std;
int map[MAX][MAX];

int main()
{
	while (1) {
		memset(map,0,sizeof(map));
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i = 0; i <=n ; i ++) {
			map[i][i] = 1;
		}
		for (int i = 0; i < m; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			map[x][y] = 1;
		}
		for (int k = 1; k <= n; k ++) {
			for (int i = 1; i<= n ; i ++) {
				if (!map[i][k]) continue;
				for (int j = 1; j <=n; j ++) {
					if (map[i][k] && map[k][j]) {
						map [i] [j] = 1;
					}
				}
			}
		}
		for (int i = 1; i<= n ; i ++) {
			for (int j = 1; j <=n; j ++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
			
		
	}
}
