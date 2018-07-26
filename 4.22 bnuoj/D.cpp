#include <cstdio>
#include <iostream>
using namespace std;
long long C(int a, int b)
{
	
}

int main()
{
	int t;
	long long a[8][8];
	a[1][1] = 0;
	a[2][1] = 0;
	a[2][2] = 2;
	a[3][1] = 0;
	a[3][2] = 0;
	a[3][3] = 8;
	for (int i = 4; i <= 7; i ++) {
		long long e = i * (i - 1) / 2;
		a[i][i] = (long long)( ) * (i + 1) * ((long long)1 << (e - i) );
		a[i][i - 1] = ((long long)(1) << (e) ) - a[i][i];
		for (int j = i - 2; j >= 1; j --) {
			a[i][j] = 0;
		}
//		for (int j = i - 1; j >= 1; j --) {
//			a[i][j] = a[j][j];
//			for (int k = j; k < i; k ++) {
//				a[i][j] *= (long long)1 << j;
//			}
//			for (int k = j + 1; k <= i; k ++) {
//				a[i][j] -= a[i][k];
//			}
//			if (a[i][j] < 0) {
//				a[i][j] = 0;
//			}
//		}
		
	}
	scanf("%d", &t);
	while (t --) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i ++) {
			printf("%lld\n", a[n][i]);
		}
	}
	
	return 0;
}
