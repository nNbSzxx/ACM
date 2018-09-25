#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e4 + 10;

struct point {
    int x, y;
    bool operator==(const point& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
} p[20 * MAX];
int n;
int cnt;

bool cmp(const point& p1, const point& p2)
{
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    } else {
        return p1.y < p2.y;
    }
}

void solve(int l, int r)
{
    if (r - l < 1) {
        return ;
    }
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    int x = p[mid].x;
    for (int i = l; i <= r; i ++) {
        p[cnt].x = x;
        p[cnt].y = p[i].y;
        ++ cnt;
    }
    return ;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    cnt = n + 1;
    sort(p + 1, p + 1 + n, cmp);
    solve(1, n);
    sort(p + 1, p + cnt, cmp);
    int ed = unique(p + 1, p + cnt) - (p + 1);
    printf("%d\n", ed);
    for (int i = 1; i <= ed; i ++) {
        printf("%d %d\n", p[i].x, p[i].y);
    }
    return 0;
}
