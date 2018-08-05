#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;
struct Point {
    long long x, y;
    Point() {}
    Point(long long xx, long long yy): x(xx), y(yy) {}
    Point operator+(const Point& rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator-(const Point& rhs) const {
        return Point(x - rhs.x, y + rhs.y);
    }
    Point operator*(long long rhs) const {
        return Point(x * rhs, y * rhs);
    }
} p[MAX];
int n;

long long det(const Point& p1, const Point& p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}



int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%lld%lld", &p[i].x, &p[i].y);
        }
    }

    return 0;
}
