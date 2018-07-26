#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
double map[105][105];
int xx[105],yy[105], vis[105], n, flag;
double d[105];
inline double dis(int x1, int y1, int x2, int y2)
{
	return sqrt(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
double prim(void) 
{
	flag = 1;
	memset(vis,0,sizeof(vis));
	for (int i = 1; i <= n; i ++) {
		d[i] = map[1][i];
	}
	vis[1] = 1;
	double minn, ans = 0;
	int minid;
	for (int i = 1; i < n; i ++) {
		minn = 1010; minid = 0;
 		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && d[j] < minn) {
				minn = d[j];
				minid = j;
			}
		}
		if (minid == 0) {
			flag = 0;
			return 0;
		}
		vis[minid] = 1;
		ans += minn;
		for (int j = 1; j <= n; j ++) {
			if (!vis[j]) {
				d[j] = min(d[j], map[minid][j]);
			}
		}
	}
	return ans;
}
int main()
{
	int t,x,y;
	scanf("%d",&t);
	while (t --) {
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d",&xx[i],&yy[i]);
			for (int j = 1; j <= i; j ++) {
				if (i == j) {
					map[i][j] = 1010;
				} else {
					double t = dis(xx[i],yy[i],xx[j],yy[j]);
					if (t >= 10 && t <= 1000) {
						map[i][j] = map[j][i] = t;
					} else {
						map[i][j] = map[j][i] = 1010;
					}
				}
			}
		}
		double ans = prim() * 100;
		if (flag) {
			printf("%.1lf\n",ans);
		} else {
			printf("oh!\n");
		}
	}
	return 0;
}
