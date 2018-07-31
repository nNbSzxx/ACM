#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
struct Tree {
    int l, r;
    int maxx;
} t[MAX << 2];
int n, q, cnt, last, cntn;
int lbound[MAX];

void maintain(int x)
{
    t[x].maxx = max(t[x << 1].maxx, t[x << 1 | 1].maxx);
}

void build(int x, int l, int r)
{
    t[x].l = l;
    t[x].r = r;
    if (l == r) {
        ++ cntn;
        int a;
        scanf("%d", &a);
        if (a != last) {
            lbound[++ cnt] = cntn;
            last = a;
        }
        t[x].maxx = cntn - lbound[cnt] + 1;
        //printf("%d %d\n", cntn, t[x].maxx);
        return ;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    maintain(x);
    return ;
}

int query(int x, int l, int r)
{
    if (l > r) {
        return 0;
    }
    if (l <= t[x].l && t[x].r <= r) {
        return t[x].maxx;
    }
    int mid = (t[x].l + t[x].r) >> 1;
    if (r <= mid) {
        return query(x << 1, l, r);
    } else if (mid + 1 <= l) {
        return query(x << 1 | 1, l, r);
    } else {
        return max(query(x << 1, l, mid), query(x << 1 | 1, mid + 1, r));
    }
}

int bins(int x)
{
    int id = lower_bound(lbound + 1, lbound + 1 + cnt, x) - (lbound);
    return lbound[id];
}

int main()
{
    while (~scanf("%d", &n), n) {
        scanf("%d", &q);
        last = MAX;
        cnt = 0;
        cntn = 0;
        build(1, 1, n);
        lbound[++ cnt] = n + 1;
        /*
        for (int i = 1; i <= cnt; i ++) {
            printf("%d ", lbound[i]);
        }
        puts("");
        */
        while (q --) {
            int u, v;
            scanf("%d%d", &u, &v);
            int rbound = bins(u);
            //printf("rbound: %d\n", rbound);
            printf("%d\n", max(min(rbound, v + 1) - u, query(1, rbound, v)));
        }
    }
    return 0;
}
