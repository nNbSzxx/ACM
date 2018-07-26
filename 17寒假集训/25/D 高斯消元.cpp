#include <cstring>
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
const int MAX = 35;
using namespace std;
	int t,n,x,y;
	int s[MAX],e[MAX];
	int map[MAX][MAX + 1];
inline int gcd(int a, int b)
{
	int r = 1;
	while (r) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

inline int Lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	scanf("%d",&t);
	__int64 ans[MAX];
	ans [0] = 1;
	for (int i = 1; i < MAX; i ++) {
		ans[i] = ans[i - 1] * 2;
	}
	while (t --) {
		memset(map,0,sizeof(map));
		scanf("%d",&n);
		int flag;
		for (int i = 0; i < n ; i ++) {
			scanf("%d",&s[i]);
		}
		for (int i = 0; i < n; i ++) {
			scanf("%d",&e[i]);
		}
		while (scanf("%d%d",&x,&y), x || y) {
			map[y - 1][x - 1] = 1;
		}
		for (int i = 0; i < n; i ++) {
			map[i][n] = s[i] ^ e[i];
			map[i][i] = 1;
		}
//		for (int i = 0; i < n; i ++) {
//				for (int j = 0; j <= n; j ++) {
//					printf("%d ",map[i][j]);
//				}
//				printf("\n");
//			}
//		printf("\n");
		int k = 0; int col = 0;
		for (; k < n && col < n; k ++, col ++) {
			int maxid = k;
			for (int i = k + 1; i < n; i ++) {
				if (abs(map[i][col]) > abs(map[maxid][col])) {
					maxid = i;
				}
			}
			if (maxid != k) {
				for (int i = col; i <= n; i ++) {
					swap(map[k][i], map[maxid][i]);
				}
			}
			if (map[k][col] == 0) {
				k --;
				continue;
			}
			for (int i = k + 1; i < n; i ++) {
				if (map[i][col] != 0) {
					int lcm = Lcm(map[i][col], map[k][col]);
					int tk = lcm / map[k][col];
					int ti = lcm / map[i][col];		
					if (map[k][col] * map[i][col] < 0) {
						tk = - tk;
					}
					for (int j = col; j <= n; j ++) {
						map[i][j] = map[i][j] * ti - map[k][j] * tk;
					}
				}
			}
//			for (int i = 0; i < n; i ++) {
//				for (int j = 0; j <= n; j ++) {
//					printf("%d ",map[i][j]);
//				}
//				printf("\n");
//			}
//			printf("\n");
		}
//		for (int i = 0; i < n; i ++) {
//			for (int j = 0; j <= n; j ++) {
//				printf("%d ",map[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
		flag = 1;
		for (int i = k; i < n; i ++) {
			if (map[i][n] != 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("%d\n",ans[n - k]);
		} else {
			printf("Oh,it's impossible~!!\n");
		}
	}
	return 0;
}
