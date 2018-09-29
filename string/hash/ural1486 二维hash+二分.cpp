// 原来PQ分别用233和31，就WA了...
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define ull unsigned long long
using namespace std;
const int MAX = 510;
const ull P = 1313;
const ull Q = 3131;

char s[MAX][MAX];
ull base[MAX][MAX], hsh[MAX][MAX];
int n, m;

int x1, y1, x2, y2, ans;
struct square {
    ull h;
    int x, y;
    square() {}
    square(ull hh, int xx, int yy) : h(hh), x(xx), y(yy) {}
    bool operator== (const square& rhs) const {
        return h == rhs.h;
    }
    bool operator< (const square& rhs) const {
        return h < rhs.h;
    }
};
set<square> st;

void init()
{
    // i : Q, j : P
    base[0][0] = 1;
    for (int i = 1; i < MAX; i ++) {
        base[0][i] = base[0][i - 1] * P;
    }
    for (int i = 1; i < MAX; i ++) {
        base[i][0] = base[i - 1][0] * Q;
    }
    for (int i = 1; i < MAX; i ++) {
        for (int j = 1; j < MAX; j ++) {
            base[i][j] = base[i - 1][j] * Q + base[i][j - 1] * P - base[i - 1][j - 1] * P * Q;
        }
    }
}

ull gethash(int xl, int yl, int xr, int yr)
{
    return hsh[xr][yr] -
           hsh[xl - 1][yr] * base[xr - xl + 1][0] -
           hsh[xr][yl - 1] * base[0][yr - yl + 1] +
           hsh[xl - 1][yl - 1] * base[xr - xl + 1][yr - yl + 1];
}

bool check(int mid)
{
    st.clear();
    for (int i = 1; i + mid - 1 <= n; i ++) {
        for (int j = 1; j + mid - 1 <= m; j ++) {
            ull h = gethash(i, j, i + mid - 1, j + mid - 1);
            auto it = st.find(square(h, i, j));
            if (it != st.end()) {
                x1 = it -> x;
                y1 = it -> y;
                x2 = i;
                y2 = j;
                return true;
            } else {
                st.insert(square(h, i, j));
            }
        }
    }
    return false;
}

void bins()
{
    int l = 1, r = min(n, m), mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ;
}


int main()
{
    init();
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; i ++) {
            scanf(" %s", s[i] + 1);
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                hsh[i][j] = hsh[i][j - 1] * P +
                            hsh[i - 1][j] * Q -
                            hsh[i - 1][j - 1] * P * Q +
                            (s[i][j] - 'a' + 1);
            }
        }

        x1 = y1 = x2 = y2 = -1;
        ans = 0;
        bins();
        printf("%d\n", ans);
        if (ans != 0) {
            printf("%d %d\n%d %d\n", x1, y1, x2, y2);
        }
    }

    return 0;
}
