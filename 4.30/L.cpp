#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t,n,m;
	scanf("%d",&t);
	int maxc,maxr,summax;
	int a[55][55];
	while (t --) {
		scanf("%d%d",&n,&m);
		summax = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			maxc = -1;
			for (int j = 1; j <= m; j ++) {
				scanf("%d",&a[i][j]);
				if (a[i][j]) {
					++ cnt;
				}
				if (a[i][j] > maxc) {
					maxc = a[i][j];
				}
			}
			summax += maxc;
		}
		for (int j = 1; j <= m; j ++) {
			maxr = -1;
			for (int i = 1; i <= n; i ++) {
				if (maxr < a[i][j]) {
					maxr = a[i][j];
				}
			}
			summax += maxr;
		}
		summax *= 2;
		summax += cnt;
//		printf("%d\n",summax);
		int b,e,l,flag;
		for (int i = 1; i <= n; i ++) {
			b = 1; e = 0; l = 0; flag = 0;
			for (int j = 2; j <= m; j ++) {
				if (a[i][j] >= a[i][b] && !flag) {
					b = j;
				} else if (flag == 1 && a[i][j] < a[i][l]) {
					l = j;
					e = j;
				} else if (flag == 1 && a[i][j] >= a[i][j - 1] ) {
					e = j;
					flag = 2;
				} else if (flag == 2 && a[i][j] < a[i][e]) {
					summax += (min(a[i][e], a[i][b]) - a[i][l]) * 2;
					b = j;
					e = 0;
					l = 0;
					flag = 0;
				} else if (!flag && a[i][j] < a[i][b]) {
					l = j;
					e = j;
					flag = 1;
				}
			}
			if (a[i][e] > a[i][e - 1]) {
				summax += (min(a[i][b], a[i][e]) - a[i][l]) * 2;
			}
		}
		for (int j = 1; j <= m; j ++) {
			b = 1; e = 0; l = 0; flag = 0;
			for (int i = 2; i <= n; i ++) {
				if (a[i][j] >= a[b][j] && !flag) {
					b = i;
				} else if (flag == 1 && a[i][j] < a[l][j] && a[i][j] >= a[i - 1][j]) {
					l = i;
					e = i;
				} else if (flag == 1 && a[i][j] >= a[i - 1][j] ) {
					e = i;
					flag = 2;
				} else if (flag == 2 && a[i][j] < a[e][j]) {
					summax += (min(a[e][j], a[b][j]) - a[l][j]) * 2;
					b = i;
					e = 0;
					l = 0;
					flag = 0;
				} 
				else if (!flag && a[i][j] < a[b][j]) {
					l = i;
					e = i;
					flag = 1;
				}
			}
			if (a[e][j] > a[e - 1][j]) {
				summax += (min(a[b][j], a[e][j]) - a[l][j]) * 2;
			}
		}
		printf("%d\n",summax);
	}
	return 0;
}
