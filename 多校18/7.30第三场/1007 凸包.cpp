#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 2e5 + 10;
struct Point {
    long long x, y;
    int id; 
    Point() {}
    Point(long long xx, long long yy): x(xx), y(yy), id(0) {}
    Point operator+(const Point& rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator-(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator*(int rhs) const {
        return Point(x * rhs, y * rhs);
    }
} p[MAX];
int n, top;
int s[MAX];

long long det(const Point& p1, const Point& p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

bool cmp(const Point& p1, const Point& p2)
{
	if (p1.x != p2.x) {
		return p1.x < p2.x;
	} else if (p1.y != p2.y) {
		return p1.y > p2.y;
	} else {
		return p1.id < p2.id;
	}
}

void graham()
{
	top = 0;
	s[top ++] = 1;
	s[top ++] = 2;
	for (int i = 3; i <= n; i ++) {
		if (p[i].x == p[i - 1].x) {
			continue;
		}
		while (top >= 2) {
			int mid = s[top - 1];
			int last = s[top - 2];
			long long cr = det(p[i] - p[last], p[mid] - p[last]);
//			printf("%lld ", cr);
			if (cr > 0) {
				break;
			} else if (cr == 0 && p[mid].id < p[i].id) {
				break;
			}
			-- top;
		}
		s[top ++] = i;
	}
}

int main()
{
//	freopen("G.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%lld%lld", &p[i].x, &p[i].y);
        	p[i].id = i;
        }
        
        if (n == 2) {
        	printf("%d %d\n", p[1].id, p[2].id);
        	continue;
		}
        sort(p + 1, p + 1 + n, cmp);
        graham();
        /*
		if (top >= 4) {
        	int last2 = s[top - 2];
        	int last = s[top - 1];
        	if (det(p[last] - p[1], p[last] - p[last2]) == 0 && p[last].id > p[last2].id) {
        		-- top;
			}
		}
		*/
		printf("%d", p[s[0]].id);
		for (int i = 1; i < top; i ++) {
			printf(" %d", p[s[i]].id);
		}
		puts("");
    }

    return 0;
}
