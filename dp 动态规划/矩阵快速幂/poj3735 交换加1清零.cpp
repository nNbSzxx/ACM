#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 110;

long long mat[MAX][MAX];
int n, m, k;

void mul(long long a[MAX][MAX], long long b[MAX][MAX])
{
	long long ret[MAX][MAX];
	memset(ret, 0, sizeof ret);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (a[i][j]) {
				for (int k = 1; k <= n; k ++) {
					ret[i][k] += a[i][j] * b[j][k];
				}	
			}
		}
	}
	memcpy(a, ret, sizeof ret);
}

void qkp(int r)
{
	long long ret[MAX][MAX];
	memset(ret, 0, sizeof ret);
	for (int i = 1; i <= n; i ++) {
		ret[i][i] = 1;
	}
	while (r) {
		if (r & 1) {
			mul(ret, mat);
		}
		r >>= 1;
		mul(mat, mat);
	}
	memcpy(mat, ret, sizeof ret);
}

int main()
{
	while (~scanf("%d%d%d", &n, &m, &k), n || m || k) {
		memset(mat, 0, sizeof mat);
		++ n;
		for (int i = 1; i <= n; i ++) {
			mat[i][i] = 1;
		}
		for (int i = 1; i <= k; i ++) {
			char c;
			int a, b;
			scanf(" %c", &c);
//			printf("c: %c\n", c);
			if (c == 'g') {
				scanf("%d", &a);
				mat[a][n] ++;
			} else if (c == 'e') {
				scanf("%d", &a);
				for (int j = 1; j <= n; j ++) {
					mat[a][j] = 0;
				}
			} else {
				scanf("%d%d", &a, &b);
//				printf("a, b: %d %d\n", a, b);
				for (int j = 1; j <= n; j ++) {
					mat[n + 1][j] = mat[a][j];
				}
				for (int j = 1; j <= n; j ++) {
					mat[a][j] = mat[b][j];
				}
				for (int j = 1; j <= n; j ++) {
					mat[b][j] = mat[n + 1][j];
				}
			}
//			for (int i = 1; i <= n + 1; i ++) {
//				for (int j = 1; j <= n; j ++) {
//					printf("%d ", mat[i][j]);
//				}
//				puts("");
//			}
		}
		
		qkp(m);
		printf("%lld", mat[1][n]);
		for (int i = 2; i < n; i ++) {
			printf(" %lld", mat[i][n]);
		}
		puts("");
	}
	return 0; 
} 
