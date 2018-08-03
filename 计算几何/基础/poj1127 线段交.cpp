#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const double EPS = 1e-8;
const int MAX = 15;
struct Point {
    double x, y;
    Point() {}
    Point(double xx, double yy) : x(xx), y(yy) {}
    Point operator+(const Point& rhs) const {
        return Point(this -> x + rhs.x, this -> y + rhs.y);
    }
    Point operator-(const Point& rhs) const {
        return Point(this -> x - rhs.x, this -> y - rhs.y);
    }
    Point operator*(double num) const {
        return Point(this -> x * num, this -> y * num);
    }
};

int n;
Point beg[MAX], ed[MAX];
int father[MAX];

// 向量内积（点积）
double dot(const Point& p1, const Point& p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

// 向量外积（叉积）
double det(const Point& p1, const Point& p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

// 两个向量是否平行或反向
bool isParallel(const Point& p1, const Point& p2)
{
    return fabs(det(p1, p2)) <= EPS;
}

// 点是否在线段上
bool onSeg(const Point& b, const Point& e, const Point& p)
{
    return dot(p - b, p - e) <= 0 && fabs(det(p - b, p - e)) <= EPS;
}

// 求直线交点
Point intersect(const Point& b1, const Point& e1, const Point& b2, const Point& e2)
{
    return b1 + (e1 - b1) * (det(e2 - b2, b2 - b1) / det(e2 - b2, e1 - b1));
}

// 判断两线段是否相交
bool isSegCrossed(const Point& b1, const Point& e1, const Point& b2, const Point& e2)
{
    if (isParallel(e1 - b1, e2 - b2)) {
        return onSeg(b1, e1, b2) ||
               onSeg(b1, e1, e2) ||
               onSeg(b2, e2, b1) ||
               onSeg(b2, e2, e1);
    } else {
        Point p = intersect(b1, e1, b2, e2);
        return onSeg(b1, e1, p) && onSeg(b2, e2, p);
    }
}

int find(int x)
{
    while (x != father[x]) {
        x = father[x] = father[father[x]];
    }
    return x;
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    father[x] = y;
}

void init()
{
    for (int i = 1; i <= n; i ++) {
        father[i] = i;
    }
}


void solve()
{
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            if (isSegCrossed(beg[i], ed[i], beg[j], ed[j])) {
                merge(i, j);
            }
        }
    }
}

int main()
{
    while (~scanf("%d", &n), n) {
        init();
        for (int i = 1; i <= n; i ++) {
            scanf("%lf%lf%lf%lf", &beg[i].x, &beg[i].y, &ed[i].x, &ed[i].y);
        }
        solve();
        int u, v;
        while (~scanf("%d%d", &u, &v), u || v) {
            if (find(u) == find(v)) {
                puts("CONNECTED");
            } else {
                puts("NOT CONNECTED");
            }
        }
    }

    return 0;
}
