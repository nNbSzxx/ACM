#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 6e4 + 5;
const double EPS = 1e-6;
double m;
int n, a[MAX], last[MAX];

struct T {
    double v, lazy;
    int l, r;
} tree[MAX * 4];

void update(int x)
{
    if (tree[x].l == tree[x].r) return ;
    tree[x].v = min(tree[x << 1].v, tree[x << 1 | 1].v);
}

void pushdown(int x)
{
    if (tree[x].l == tree[x].r) return ;
    tree[x << 1].v += tree[x].lazy;
    tree[x << 1 | 1].v += tree[x].lazy;
    tree[x << 1].lazy += tree[x].lazy;
    tree[x << 1 | 1].lazy += tree[x].lazy;
    tree[x].lazy = 0;
}
void build(int x, int l, int r)
{
    tree[x].lazy = 0;
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].v = l * m;
        return ;
    }
    int mid = (l + r) >> 1;
    build (x << 1, l, mid);
    build (x << 1 | 1, mid + 1, r);
    update(x);
    return ;
}

void modify(int x, int l, int r, int v)
{
    if(l <= tree[x].l && tree[x].r <= r) {
        tree[x].v += v;
        tree[x].lazy += v;
        return ;
    }
    pushdown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (l <= mid) {
        modify(x << 1, l, r, v);
    }
    if (mid + 1 <= r) {
        modify(x << 1 | 1, l, r, v);
    }
    update(x);
}

double query(int x, int l, int r)
{
    if (l <= tree[x].l && tree[x].r <= r) {
        return tree[x].v;
    }
    pushdown(x);
    double ret = 1e9 + 7;
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (mid >= l) {
        ret = min(ret, query(x << 1, l, r));
    }
    if (mid + 1 <= r) {
        ret = min(ret, query(x << 1 | 1, l, r));
    }
    update(x);
    return ret;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
        }
        double l = 0, r = 1, ans = 1;
        for (int k = 1; k <= 25; k ++) {
            memset(last, 0, sizeof last);
            int flag = 0;
            m = (l + r) / 2;
            build(1, 1, n);
            for (int i = 1; i <= n; i ++) {
                modify(1, last[a[i]] + 1, i, 1);
                last[a[i]] = i;
                if (query(1, 1, i) <= (i + 1) * m) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                ans = m;
                r = m;
            } else {
                l = m;
            }
        }
        printf("%.10f\n", ans);
    }

}
