#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 10;
int st[MAX][20];
int n;

void init(void)
{
	for (int i = 1; (1 << i) <= n; i ++) {
		for (int j = 1; j + (1 << i) - 1 <= n; j ++) {
			st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
		}
	}
}
int query(int l, int r)
{
	int len = r - l + 1;
	int k = 0;
	while (1 << (k + 1) < len)
		k ++;
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &st[i][0]);
		}
		init();
		int flag = 0;
		for (int i = 2; i <= n; i ++) {
			int maxx = query(1, i - 1);
			for (int j = i; j + 1 <= n; j += i) {
				maxx = max(maxx, query(j + 1, min(j + i - 1, n)));
			}
			if (flag)
				printf(" ");
			else 
				flag = 1;
			printf("%d", maxx);
		}
		printf("\n");
	}
	return 0;
}






