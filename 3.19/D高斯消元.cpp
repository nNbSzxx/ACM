#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 30;
int map[MAX * MAX][MAX * MAX];
int var ;
int n,m,d;

inline int gcd(int a, int b)
{
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
inline int lcm(int a, int b)
{
	return a/gcd(a,b)*b;
}
bool gauss()
{
	int k = 0, col = 0;
	for (; k < var && col < var; k ++, col ++) {
		int maxr = k;
		for (int i = k + 1; i < var; i ++) {
			if (abs(map[i][col]) > abs(map[maxr][col])) {
				maxr = i;
			}
		}
		if (maxr != k)
			for (int i = col; i <= var; i ++) {
				swap(map[k][i], map[maxr][i]);
			}
		if (map[k][col] == 0) {
			k --;
			continue;
		}
		for (int i = k + 1; i < var; i ++) {
			if (map[i][col] == 0) {
				continue;
			}
			int l = lcm(abs(map[k][col]), abs(map[i][col]));
			int mulk = l / abs(map[k][col]);
			int muli = l / abs(map[i][col]);
			if (map[k][col] * map[i][col] < 0) {
				mulk = - mulk;
			}
			for (int j = col; j <= var; j ++) {
				map[i][j] = (map[i][j] * muli - map[k][j] * mulk) % 2;
			}
		}
	}
	for (int i = k; i < var; i ++) {
		if (map[i][var]) {
			return false;
		}
	}
	return true;
}
bool judge(int x, int y) 
{
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	return true;
} 
int main()
{

	while (~scanf("%d%d%d",&m,&n,&d), n || m || d) {
		
		var = n * m;
		memset(map,0,sizeof(map));
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m ; j ++) {
				scanf("%d",&map[i * m + j][var]);
				map[i * m + j][i * m + j] = 1;
				for (int k = 0; k <= d; k ++) {
					if (judge(i+k,j+d-k))
						map[i * m + j][(i+k)*m+(j+d-k)] = 1;
					if (judge(i+k,j-d+k))
						map[i * m + j][(i+k)*m+(j-d+k)] = 1;
					if (judge(i-k,j+d-k))
						map[i * m + j][(i-k)*m+(j+d-k)] = 1;
					if (judge(i-k,j-d+k))
						map[i * m + j][(i-k)*m+(j-d+k)] = 1;
				}
			}
		}
//		for (int i = 0; i < var; i ++) {
//			for (int j = 0; j <= var; j ++) {
//				printf("%d ",map[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
		if (gauss()) {
			printf("1\n");
		} else {
			printf("0\n");
		}
//		for (int i = 0; i < var; i ++) {
//			for (int j = 0; j <= var; j ++) {
//				printf("%d ",map[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
	}
}
