#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI=acos(-1.0);
const double EPS=1e-12;
double a,b,c;
double ans;
int main() {
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%lf%lf%lf",&a,&b,&c);
        if (b>a) swap(a,b);
        if (c>a) swap(a,c);
        if (c>b) swap(b,c);
        double t=a-b;
        printf("%.12f\n",PI*(t*t+b*b));
    }
    return 0;
}
