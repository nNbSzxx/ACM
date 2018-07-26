#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 128;
double a[MAX][MAX], p[MAX], ans[MAX][MAX];
int n, x;

void mul(double (*a)[MAX], double (*b)[MAX], double (*c)[MAX])
{
	double ret[MAX][MAX];
	memset(ret, 0, sizeof(ret));
	for (int i = 0; i < MAX; i ++) {
		for (int j = 0; j < MAX; j ++) {
			for (int k = 0; k < MAX; k ++) {
				ret[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	memcpy(c, ret, sizeof(ret));
}
void pow(int r)
{
	while (r) {
		if (r & 1) {
			mul(ans, a, ans);
		}
		r >>= 1;
		mul(a, a, a);
	}
}
int main()
{
	cin >> n >> x;
	for (int i = 0; i <= x; i ++) {
		cin >> p[i];
	}	
	for (int i = 0; i < MAX; i ++) {
		for (int j = 0; j < MAX; j ++) {
			a[i][j] = p[i ^ j];
		}
	}
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < MAX; i ++) {
		ans[i][i] = 1;
	}
	pow(n);
	printf("%.9lf", 1 - ans[0][0]);
	return 0;
}
