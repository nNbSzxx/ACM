#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 105;

int main()
{
	int map[MAX][MAX];
	int n;
	while  (~scanf("%d",&n)) {
		memset(map,0,sizeof(map));
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n ; j++) {
				int t;
				scanf("%d",&t);
				map[i][j] = map[i - 1][j] + t;
			}
		}
		int ma = -99999;
		for (int i = 0; i <= n; i++) {
			for (int j = i + 1; j <= n; j ++) {
				int sum = 0;
				for (int k = 1; k <= n; k ++) {
					int t = map[j][k] - map[i][k];
					sum += t;
					if (sum < 0) sum = 0;
					if (sum > ma) ma = sum;
				}
			}
		}
		printf("%d\n",ma);
	}
	return 0;
}

