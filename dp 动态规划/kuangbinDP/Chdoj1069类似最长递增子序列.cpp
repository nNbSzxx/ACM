#include <bits/stdc++.h>
using namespace std;
int n, dp[145];
struct box {
	int a, b, c;
} bx[145];

void add(int id, int a, int b, int c)
{
	bx[id].a = a;
	bx[id].b = max(b, c);
	bx[id].c = min(b, c);
}

bool cmp(const box& b1, const box& b2)
{
	return b1.b > b2.b || (b1.b == b2.b && b1.c > b2.c);
}
int main()
{
	int tc = 1;
	while (scanf("%d", &n), n) {
		for (int i = 1; i <= n; i ++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add(3 * i - 3 + 1, a, b, c);
			add(3 * i - 3 + 2, b, a, c);
			add(3 * i - 3 + 3, c, a, b);
		}
		sort(bx + 1, bx + 1 + 3 * n, cmp);
		for (int i = 1; i <= 3 * n; i ++) {
			dp[i] = bx[i].a;
			for (int j = 1; j < i; j ++) {
				if (bx[i].b < bx[j].b && bx[i].c < bx[j].c) {
					dp[i] = max(dp[i], dp[j] + bx[i].a);
				}
			}
		}
		int ans = -1;
		for (int i = 1; i <= 3 * n; i ++) {
			ans = max(ans, dp[i]);
		}
		printf("Case %d: maximum height = %d\n", tc ++, ans);
	}
	
	return 0;
}
