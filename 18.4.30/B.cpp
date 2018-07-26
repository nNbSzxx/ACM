#include <bits/stdc++.h>
using namespace std;
const int MAX = 50010;
int b, k, cd, cp;

struct perc {
    int id;
    int p;
} pc[MAX];

struct dd {
    int id;
    int inc;
} d[MAX];

bool cmp1(const dd& d1, const dd& d2)
{
    return d1.inc > d2.inc;
}
bool cmp2(const perc& pc1, const perc& pc2)
{
    return pc1.p > pc2.p;
}
int main()
{
    freopen("buffcraft.in", "r", stdin);
    freopen("buffcraft.out", "w", stdout);
    scanf("%d%d%d%d", &b, &k ,&cd, &cp);
    for (int i = 1; i <= cd; i ++) {
        scanf("%d", &d[i].inc);
        d[i].id = i;
    }
    for (int i = 1; i <= cp; i ++) {
        scanf("%d", &pc[i].p);
        pc[i].id = i;
    }
    sort(d + 1, d + 1 + cd, cmp1);
    sort(pc + 1, pc + 1 + cp, cmp2);
    /*
    for (int i = 1; i <= cp; i ++) {
        printf("%d ", pc[i].p);
    }
    puts("");
    */
    double sum = b;
    int lim = min(k, cd);
    for (int i = 1; i <= lim; i ++) {
        sum += d[i].inc;
    }
    int maxdid = k, maxpid = 0;
    double pp = 100;
    if (lim < k) {
        maxdid = lim;
        int lim2 = min(k, cd + cp);
        maxpid = k - lim;
        for (int i = lim + 1; i <= lim2; i ++) {
            pp += pc[i - lim].p;
        }
        if (cd + cp <= k) {
            printf("%d %d\n", cd, cp);
            for (int i = 1; i <= cd; i ++) {
                if (i != 1)
                    printf(" %d", d[i].id);
                else
                    printf("%d", d[i].id);
            }
            puts("");
            for (int i = 1; i <= cp; i ++) {
                if (i != 1)
                    printf(" %d", pc[i].id);
                else
                    printf("%d", pc[i].id);
            }
            return 0;
        }
    }
    double maxx = sum * pp;
    int curdid = maxdid, curpid = maxpid;
    for (int i = 1; i <= k; i ++) {
        ++ curpid;
        if (curdid == 0 || curpid > k || curpid > cp) {
            break;
        }
        sum -= d[curdid].inc;
        pp += pc[curpid].p;
        -- curdid;
        double psum = sum * pp;
        if (psum > maxx) {
            maxx = psum;
            maxdid = curdid;
            maxpid = curpid;
        }

    }
    printf("%d %d\n", maxdid, maxpid);
    for (int i = 1; i <= maxdid; i ++) {
        if (i != 1)
            printf(" %d", d[i].id);
        else
            printf("%d", d[i].id);
    }
    puts("");
    for (int i = 1; i <= maxpid; i ++) {
        if (i != 1)
            printf(" %d", pc[i].id);
        else
            printf("%d", pc[i].id);
    }
    puts("");
    return 0;
}
