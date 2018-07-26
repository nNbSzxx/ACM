#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 1e4 + 10;

int main()
{
	double x1,x2,x3,y1,y2,y3;
	double a,b,c,k,h;
	double s;
	int t,i;
	scanf("%d",&t);
	while (t --) {
		    scanf("%lf %lf",&x1,&y1);
            scanf("%lf %lf",&x2,&y2);
            scanf("%lf %lf",&x3,&y3);
            a = (y2 - y1)/((x2 - x1)*(x2 - x1));
            b = -2 * a * x1;
            c = y1 - a * x1 * x1 - b * x1;
            k = (y2 - y3)/(x2 - x3);
            h = y2 - k *  x2;
            s = a/3 * (x3*x3*x3 - x2*x2*x2) + (b - k)/2 * (x3*x3 - x2*x2) + (c - h) * (x3 - x2);
            printf("%.2lf\n",s);
	}
	return 0;
}

