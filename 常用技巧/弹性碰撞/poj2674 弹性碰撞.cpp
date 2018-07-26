#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 32010;
int n;
double l, v;
char name[MAX][255];
struct P {
    int dir;
    double pos;
    int id;
} p[MAX];

bool cmp(const P& p1, const P& p2)
{
    return p1.pos < p2.pos;
}

int main()
{
    while (~scanf("%d", &n), n) {
        scanf("%lf%lf", &l, &v);
        double maxx = -1;
        int maxid = -1;
        int maxdir = -1;
        int pcnt = 0, ncnt = 0;
        for (int i = 1; i <= n; i ++) {
            char c;
            scanf(" %c%lf %s", &c, &p[i].pos, name[i]);
            p[i].dir = (c == 'p' || c == 'P');
            p[i].id = i;
            if (p[i].dir) {
                if (l - p[i].pos > maxx) {
                    maxx = l - p[i].pos;
                    maxid = i;
                    maxdir = 1;
                }
                ++ pcnt;
            } else {
                if (p[i].pos > maxx) {
                    maxx = p[i].pos;
                    maxid = i;
                    maxdir = 0;
                }
                ++ ncnt;
            }
        }
        sort(p + 1, p + 1 + n, cmp);
        int id;
        if (maxdir) {
            id = p[n - pcnt + 1].id;
        } else {
            id = p[ncnt].id;
        }
        printf("%13.2f %s\n", int(maxx / v * 100) / 100.0, name[id]);
    }
    return 0;
}
