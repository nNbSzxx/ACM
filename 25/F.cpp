#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Point{
	double x,y;
};

int main()
{
	int t;
	scanf("%d",&t);
	double a,b,c;
	Point p[3];	
	while (t --) {
		for (int i = 0; i < 3; i ++) {
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		double q = p[0].x;
		double h = p[0].y;
		
		a = (p[1].y - h) / (p[1].x -q) / (p[1].x - q);
		b = -2 * a * q;
		c = q * q + h;
		a /= 3;
		b /= 2;
		double k = (p[1].y - p[2].y) / (p[1].x - p[2].x);
		double m = p[1].y - k * p[1].x;
		k /= 2;
		double ans;
		if (a > 0) {
			ans = k * p[2].x * p[2].x + m * p[2].x - k * p[1].x * p[1].x + m * p[1].x - (a * p[2].x * p[2].x * p[2].x + b * p[2].x * p[2].x + c * p[2].x - a * p[1].x * p[1].x * p[1].x + b * p[1].x * p[1].x + c * p[1].x);
		} else {
			ans =  - (k * p[2].x * p[2].x + m * p[2].x - k * p[1].x * p[1].x + m * p[1].x) + (a * p[2].x * p[2].x * p[2].x + b * p[2].x * p[2].x + c * p[2].x - a * p[1].x * p[1].x * p[1].x + b * p[1].x * p[1].x + c * p[1].x);
		}
		printf("%.2f\n",ans);
	}
	
	return 0;
}
