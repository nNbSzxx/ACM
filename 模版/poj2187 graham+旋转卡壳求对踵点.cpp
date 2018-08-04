#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 5e4 + 10;
const int INF = 1e5 + 10;
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
    bool operator<(const Point& rhs) const {
        if (x != rhs.x) {
            return x < rhs.x;
        } else {
            return y < rhs.y;
        }
    }
} p[MAX];
int n;
vector<Point> s;

bool cmp(const Point& p1, const Point& p2)
{
    double a = atan2(p1.y - p[0].y, p1.x - p[0].x);
    double b = atan2(p2.y - p[0].y, p2.x - p[0].x);
    if (a != b) {
        return a < b;
    } else {
        return p1.x < p2.x;
    }
}

double dis2(const Point& p1, const Point& p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

double det(const Point& p1, const Point& p2)
{
    return (p1.x * p2.y - p1.y * p2.x);
}

void graham()
{
    s.clear();
    s.push_back(p[0]);
    s.push_back(p[1]);
    for (int i = 2; i < n; i ++) {
        while (s.size() >= 2) {
            Point mid = s.back();
            s.pop_back();
            Point last = s.back();
            if (det(mid - p[i], mid - last) > 0) {
                s.push_back(mid);
                break;
            }
        }
        s.push_back(p[i]);
    }
}

double rotation()
{
	int size = s.size();
	if (size == 1) {
        return 0;
    } else if (size == 2) {
        return dis2(s[0], s[1]);
    }

    int bg = 0;
    int ed = 0;
    for (int k = 1; k < size; k ++) {
        if (s[k] < s[bg]) {
            bg = k;
        }
        if (s[ed] < s[k]) {
            ed = k;
        }
    }
    int i = bg, j = ed;
    double dis = -1;
    while (i != ed || j != bg) {
        dis = max(dis, dis2(s[i], s[j]));
        if (det(s[(i + 1) % size] - s[i], s[(j + 1) % size] - s[j]) < 0) {
            i = (i + 1) % size;
        } else {
            j = (j + 1) % size;
        }
    }
    return dis;
}

int main()
{
    while (~scanf("%d", &n)) {
        Point bottom;
        int id;
        bottom.x = bottom.y = INF;
        for (int i = 0; i < n; i ++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            if (p[i].x < bottom.x || (p[i].x == bottom.x && p[i].y < bottom.y)) {
                bottom = p[i];
                id = i;
            }
        }
        swap(p[id], p[0]);
        
        sort(p + 1, p + n, cmp);
        graham();
        printf("%.0f\n", rotation());
    }
    return 0;
}
