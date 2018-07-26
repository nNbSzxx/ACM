#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1e4 + 10;
const double PRE = 1e-8;
int n;
struct point {
    double x, y, z, dis, d1, d2, d3;
} p[MAX];
inline double dsqr(double x, double y)
{
    return (x-y) * (x- y);
}
int findseg(double dis)
{
    int l = 1, r = n + 1, ret = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (p[mid].dis <= dis) {
            ret = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ret;
}
int main()
{

    double vp, vs;
    cin >> n;
    for (int i = 1; i <= n + 1; i ++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    double x, y, z;

    cin >> vp >> vs;
     cin >> x >> y >> z;
    p[1].dis = 0;
    for (int i = 2; i <= n + 1; i ++) {
        p[i].dis = p[i-1].dis + sqrt(dsqr(p[i].x,p[i-1].x) + dsqr(p[i].y, p[i-1].y) + dsqr(p[i].z, p[i-1].z));
    }
    for (int i = 1; i <= n; i ++) {
        double t = (p[i + 1].dis - p[i].dis) / vs;
        p[i].d1 = (p[i + 1].x - p[i].x) / t;
        p[i].d2 = (p[i + 1].y - p[i].y) / t;
        p[i].d3 = (p[i + 1].z - p[i].z) / t;
    }
    double l = 0, r = p[n + 1].dis + 1e-7;
    point ansp;
    //cout << l << endl << r << endl;
    double dis_s = -1;
    while ((r - l) >= PRE) {
        double mid = (l + r) / 2;
        //cout << r << " " << l << " " << mid << endl;
        int id = findseg(mid);
        double t1 = mid / vs;
        double t2 = p[id].dis / vs;
        double t = t1 - t2;
        point pp;
        pp.x = p[id].x + (p[id].d1 * t);
        pp.y = p[id].y + (p[id].d2 * t);
        pp.z = p[id].z + (p[id].d3 * t);
        double dis = sqrt(dsqr(x, pp.x) + dsqr(y, pp.y) + dsqr(z, pp.z));
        double tp = dis / vp;
        if (tp <= t1) {
            r = mid;
            dis_s = mid;
            ansp = pp;
        } else {
            l = mid;
        }
    }
    if (dis_s < 0) {
        puts("NO");
    } else {
        puts("YES");
        printf("%.10lf\n", dis_s / vs);
        printf("%.10lf %.10lf %.10lf\n", ansp.x, ansp.y, ansp.z);
    }
    return 0;
}

