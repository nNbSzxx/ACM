#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 10010;
const double INF = 80000;

struct point {
    double x, y;
} p[MAX];
int n;
double d;
bool ok[MAX];

bool cmp(const point& p1, const point& p2)
{
    return p1.x < p2.x;
}

void mergeSort(int l, int mid, int r)
{
    point b[MAX];
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (p[i].y < p[j].y) {
            b[k] = p[i];
            i ++;
            k ++;
        } else {
            b[k] = p[j];
            j ++;
            k ++;
        }
    }
    while (i <= mid) {
        b[k] = p[i];
        i ++;
        k ++;
    }
    while (j <= r) {
        b[k] = p[j];
        j ++;
        k ++;
    }
    for (int i = l; i <= r; i ++) {
        p[i] = b[i];
    }
}

void getClosest(int l, int r)
{
    if (r - l <= 1) {
        return ;
    }
    int mid = (l + r) >> 1;
    double x = p[mid].x;
    getClosest(l, mid);
    getClosest(mid + 1, r);
    mergeSort(l, mid, r);

    for (int i = l; i <= r; i ++) {
        if (fabs(p[i].x - x) >= d) {
            ok[i] = 0;
            continue;
        }
        ok[i] = 1;
        for (int j = i - 1; j >= l; j --) {
            if (!ok[j]) {
                continue;
            }
            double dx = p[i].x - p[j].x;
            double dy = p[i].y - p[j].y;
            if (dy >= d) {
                break;
            }
            d = min(d, sqrt(dx * dx + dy * dy));
        }
    }
}

int main()
{
    while (~scanf("%d", &n), n) {
        for (int i = 1; i <= n; i ++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        sort(p + 1, p + 1 + n, cmp);
        d = INF;
        memset(ok, 0, sizeof ok);
        getClosest(1, n);
        if (d >= 10000) {
            puts("INFINITY");
        } else {
            printf("%.4f\n", d);
        }
    }
    return 0;
}
