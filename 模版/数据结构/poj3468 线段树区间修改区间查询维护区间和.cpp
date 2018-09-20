#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
struct Tree {
    long long sum;
    int l, r, len;
    long long tag;
} t[MAX << 2];
int n, q;

void maintain(int x)
{
    t[x].sum = t[x << 1].sum + t[x << 1 | 1].sum;
}

void pushdown(int x)
{
    if (t[x].tag) {
        t[x << 1].sum += t[x].tag * t[x << 1].len;
        t[x << 1].tag += t[x].tag;
        t[x << 1 | 1].sum += t[x].tag * t[x << 1 | 1].len;
        t[x << 1 | 1].tag += t[x].tag;
        t[x].tag = 0;
    }
}

void build(int x, int l, int r)
{
    t[x].l = l;
    t[x].r = r;
    t[x].len = r - l + 1;
    if (l == r) {
        scanf("%lld", &t[x].sum);
        return ;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    maintain(x);
}

void modify(int x, int l, int r, int del)
{
    if (l <= t[x].l && t[x].r <= r) {
        t[x].sum += t[x].len * del;
        t[x].tag += del;
        return ;
    }
    pushdown(x);
    int mid = (t[x].l + t[x].r) >> 1;
    if (r <= mid) {
        modify(x << 1, l, r, del);
    } else if (l >= mid + 1) {
        modify(x << 1 | 1, l, r, del);
    } else {
        modify(x << 1, l, mid, del);
        modify(x << 1 | 1, mid + 1, r, del);
    }
    maintain(x);
}

long long query(int x, int l, int r)
{
    if (l <= t[x].l && t[x].r <= r) {
        return t[x].sum;
    }
    pushdown(x);
    int mid = (t[x].l + t[x].r) >> 1;
    long long ret = 0;
    if (r <= mid) {
        ret = query(x << 1, l, r);
    } else if (l >= mid + 1) {
        ret = query(x << 1 | 1, l, r);
    } else {
        ret = query(x << 1, l, mid);
        ret += query(x << 1 | 1, mid + 1, r);
    }
    maintain(x);
    return ret;
}

int main()
{
    while (~scanf("%d%d", &n, &q)) {
        build(1, 1, n);
        while (q --) {
            char c;
            int l, r, del;
            scanf(" %c", &c);
            if (c == 'Q') {
                scanf("%d%d", &l, &r);
                printf("%lld\n", query(1, l, r));
            } else {
                scanf("%d%d%d", &l, &r, &del);
                modify(1, l, r, del);
            }
        }
    }
    return 0;
}
