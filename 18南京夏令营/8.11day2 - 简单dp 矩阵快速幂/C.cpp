#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX = 110;
int a[MAX][MAX], b[MAX][MAX], res[MAX][MAX];
int p, q, r;

int main()
{
	freopen("mmul.in", "r", stdin);
	freopen("mmul.out", "w", stdout);
	scanf("%d%d%d", &p, &q, &r);
	for (int i = 1; i <= p; i ++) {
		for (int j = 1; j <= q; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= q; i ++) {
		for (int j = 1; j <= r; j ++) {
			scanf("%d", &b[i][j]);
		}
	}
	for (int i = 1; i <= p; i ++) {
		for (int j = 1; j <= r; j ++) {
			for (int k = 1; k <= q; k ++) {
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for (int i = 1; i <= p; i ++) {
		for (int j = 1; j <= r; j ++) {
			printf("%d ", res[i][j]);
		}
		puts("");
	}
	return 0;
}



