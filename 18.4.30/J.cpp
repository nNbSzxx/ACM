#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-11;
const int MAX = 1e4 + 10;

int sx, sy, fx, fy;
int n, k, v;
int wx[MAX], wy[MAX];

int main()
{
    //freopen("joy.in", "r", stdin);
    //freopen("joy.out", "w", stdout);
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    scanf("%d%d%d", &n, &k, &v);
    int t, wxx, wyy;
    int lastt = 0, lastwx, lastwy;
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d%d", &t, &wxx, &wyy);
        if (i != 1) {
            for (int j = lastt; j < t; j ++) {
                //printf("%d %d %d\n", j, lastwx, lastwy);
                wx[j] = lastwx;
                wy[j] = lastwy;
            }
            //puts("");
        }
        lastt = t;
        lastwx = wxx;
        lastwy = wyy;
    }
    for (int i = lastt; i < k; i ++) {
        //printf("%d %d %d\n", i, lastwx, lastwy);
        wx[i] = lastwx;
        wy[i] = lastwy;
    }
    //puts("");
    long long wsx = sx, wsy = sy;
    for (int i = 0; i < k; i ++) {
        wsx += wx[i];
        wsy += wy[i];
    }
    long long dis2 = 1LL * (fx - wsx) * (fx - wsx) + 1LL * (fy - wsy) * (fy - wsy);
    if (dis2 > 1LL * (1LL * v * k) * (1LL * v * k)) {
        puts("No");
        return 0;
    }
    puts("Yes");
    double vx = 1.0 * (fx - wsx) / k + EPS;
    double vy = 1.0 * (fy - wsy) / k + EPS;
    double px = sx, py = sy;
    for (int i = 0; i < k; i ++) {
        px += vx + wx[i];
        py += vy + wy[i];
        printf("%f %f\n", px, py);
    }
    return 0;
}
