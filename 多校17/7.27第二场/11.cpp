#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 105;
int n, vis[MAX * 6][MAX * 6];
int x[510], y[510];

int main()
{
	while (cin >> n) {
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d", &x[i], &y[i]);
			x[i] += 300;
			y[i] += 300;
			vis[x[i]][y[i]] = 1;
		}
		long long ans = 0;
		int xx, yy, tx, ty;
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= n; j ++) {
				xx = x[j] - x[i];
				yy = y[j] - y[i];
				tx = - yy;
				ty = xx;
				if (vis[x[i] + tx][y[i] + ty] && vis[x[j] + tx][y[j] + ty]) {
					++ ans;
				}
				tx = yy;
				ty = - xx;
				if (vis[x[i] + tx][y[i] + ty] && vis[x[j] + tx][y[j] + ty]) {
					++ ans;
				}
			}
		}
		printf("%lld\n", ans / 4);
	}
	
	return 0;
}
