#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 105;
const double INF = 9999999;
double map[MAXN][MAXN];
struct Vec {
	double x,y;
};
Vec vec[MAXN];
int n;
int visit[MAXN];

inline double Min(double a, double b)
{
	return a < b ? a : b;
} 

double prim(void)
{
	double ans = 0.0;
	double lowcost[MAXN];
	lowcost[1] = 0;
	visit[1] = 1;
	for (int i = 2; i <= n ; i ++) {
		lowcost[i] = map[1][i];
	}
	double min = INF; 
	int minid ;
	for (int i = 1; i < n; i ++) {
		min = INF;
		for (int j = 1; j <= n; j ++) {
			if (!visit[j] && lowcost[j] < min) {
				min = lowcost[j];
				minid = j;
			} 
		}
		ans += lowcost[minid];
		visit[minid] = 1;
		lowcost[minid]=0;
		for (int j = 1; j <= n; j ++) {
			if (map[minid][j] != INF ) {
				lowcost[j] = Min(map[minid][j], lowcost[j]);
			}
		}
	}
	return ans;
}

int main()
{
	while (~scanf("%d",&n)) {
		memset(visit,0,sizeof(visit));
		for (int i = 1; i <= n; i ++) {
			scanf("%lf%lf",&vec[i].x,&vec[i].y);
			for (int j = 1; j <= i; j ++) {
				map[j][i] = map[i][j] = sqrt((vec[i].x - vec[j].x)*(vec[i].x - vec[j].x)+(vec[i].y - vec[j].y)*(vec[i].y - vec[j].y));
			}
		}
		double ans = prim();
		printf("%.2f\n",ans);
	}
	return 0;
}
