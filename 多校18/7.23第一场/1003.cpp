#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 3e3 + 30;

struct Point {
    int x, y, id;
} p[MAX];

bool cmp(const Point& p1, const Point& p2)
{
    if (p1.x < p2.x) {
        return true;
    } else if (p1.x > p2.x) {
        return false;
    } else {
        return p1.y < p2.y;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= 3 * n; i ++) {
            scanf("%d%d", &p[i].x, &p[i].y);
            p[i].id = i;
        }
        sort(p + 1, p + 1 + 3 * n, cmp);
        for (int i = 1; i <= 3 * n; i += 3) {
            printf("%d %d %d\n", p[i].id, p[i + 1].id, p[i + 2].id);
        }
    }
    return 0;
}
