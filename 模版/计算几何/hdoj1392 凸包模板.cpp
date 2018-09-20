#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;
const int MAX = 110;
const int INF = 4e4 + 10;
const double EPS = 1e-6;
struct Point {
    double x, y;
    Point() {}
    Point(double xx, double yy): x(xx), y(yy) {}
    Point operator+(const Point& rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator-(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator*(double rhs) const {
        return Point(x * rhs, y * rhs);
    }
} p[MAX];
int n;
stack<Point> s;

// 叉积，两向量角度为p1到p2逆时针旋转的角度，180度以内叉积为正，否则为负
double det(const Point& p1, const Point& p2)
{
    return (p1.x * p2.y - p1.y * p2.x);
}

// 极角排序，atan2(y, x)求极角
bool cmp(const Point& p1, const Point& p2)
{
    double a = atan2(p1.y - p[1].y, p1.x - p[1].x);
    double b = atan2(p2.y - p[1].y, p2.x - p[1].x);
    if (a != b) {
        return a < b;
    } else {
        return p1.x < p2.x;
    }
}

double dis(const Point& p1, const Point& p2)
{
    return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void graham()
{
    while (!s.empty()) {
        s.pop();
    }
    s.push(p[1]);
    s.push(p[2]);
    for (int i = 3; i <= n; i ++) {
        while (s.size() >= 2) {
            Point mid = s.top();
            s.pop();
            Point last = s.top();
            if (det(mid - p[i], mid - last) > 0) {
                s.push(mid);
                break;
            }
        }
        s.push(p[i]);
    }
}

int main()
{
    while (~scanf("%d", &n), n) {
        Point bottom;
        bottom.x = INF;
        bottom.y = INF;
        int id = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            if (p[i].x < bottom.x || (p[i].x == bottom.x && p[i].y < bottom.y)) {
                bottom = p[i];
                id = i;
            }
        }
        if (n == 1) {
            printf("0.00\n");
            continue;
        } else if (n == 2) {
            printf("%.2f\n", dis(p[1], p[2]));
            continue;
        }

        swap(p[1], p[id]);
        sort(p + 2, p + n + 1, cmp);
        graham();

        // 求凸包周长
        double ans = dis(s.top(), p[1]);
        Point last = s.top();
        s.pop();
        while (!s.empty()) {
            Point now = s.top();
            s.pop();
            ans += dis(now, last);
            last = now;
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
