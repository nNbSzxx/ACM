#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 55;
const double EPS = 1e-10;
const double g = 9.8;
int n, v, pigx, pigy;
int lf[MAX], bw[MAX], rt[MAX], tp[MAX];

double geth(double vy, double t)
{
    return vy * t - g * t * t / 2;
}

int loc(double l, double r, double x)
{
    if (x < l + EPS) {
        return -1;
    } else if (x > r - EPS) {
        return 1;
    } else {
        return 0;
    }
}

bool check(double x, double h)
{
    double a = g * g / 4.0;
    double b = 1.0 * h * g - 1.0 * v * v;
    double c = 1.0 * h * h + 1.0 * x * x;
    double del = b * b - 4.0 * a * c;
    if (del <= -EPS) {
        return false;
    }
    if (del > -EPS && del < 0) {
        del = 0;
    }

    for (int sign = -1; sign <= 1; sign += 2) {

        double t0 = (-b + sign * sqrt(del)) / (a * 2.0);
        if (t0 <= 0) {
            continue;
        }
        t0 = sqrt(t0);
        double vx = 1.0 * x / t0;
        double vy = (0.5 * g * t0 * t0 + h) / t0;

        double hpigx = geth(vy, 1.0 * pigx / vx);
        if (hpigx + EPS < pigy) {
            continue;
        }

        bool ok = true;
        for (int i = 1; i <= n; i ++) {
            if (pigx == rt[i]) {
                if (hpigx > bw[i] && pigy < tp[i]) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            continue;
        }
        for (int i = 1; i <= n; i ++) {
            if (lf[i] >= pigx) {
                continue;
            }
            int ly = loc(bw[i], tp[i], geth(vy, 1.0 * lf[i] / vx));
            int ry = loc(bw[i], tp[i], geth(vy, 1.0 * rt[i] / vx));
            if (ly * ry <= 0) {
                ok = false;
                break;
            }
            if (ly == -1 && ry == -1) {
                int hx = loc(lf[i], rt[i], vx * (vy / g));
                int hy = loc(bw[i], tp[i], geth(vy, vy / g));
                if (hx == 0 && hy >= 0) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            continue;
        } else {
            return true;
        }
    }
    return false;
}

int main()
{
    while (~scanf("%d%d%d%d", &n, &v, &pigx, &pigy)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d%d%d%d", &lf[i], &bw[i], &rt[i], &tp[i]);
            rt[i] = min(rt[i], pigx);
        }
        bool find = check(pigx, pigy);
        if (find) {
            puts("Yes");
            continue;
        }
        for (int i = 1; i <= n; i ++) {
            find = check(lf[i], tp[i]);
            if (find) {
                break;
            }
            find = check(rt[i], tp[i]);
            if (find) {
                break;
            }
        }
        if (find) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
