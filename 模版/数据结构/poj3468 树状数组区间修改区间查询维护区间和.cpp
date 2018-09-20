#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
long long treesum0[MAX], treesum1[MAX]; // 存储的是差分
long long a[MAX];
int n, q;

inline int lowbit(int x)
{
    return x & (-x);
}

void init()
{
    memset(treesum0, 0, sizeof treesum0);
    memset(treesum1, 0, sizeof treesum1);
}

// 这里还是单点修改
void modify(long long *b, int x, long long del)
{
    for (int i = x; i <= n + 5; i += lowbit(i)) {
        b[i] += del;
    }
}

long long query(long long *b, int r)
{
    long long ret = 0;
    for (int i = r; i; i -= lowbit(i)) {
        ret += b[i];
    }
    return ret;
}

int main()
{
    while (~scanf("%d%d", &n, &q)) {
        init();
        a[0] = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%lld", &a[i]);
            a[i] += a[i - 1];
        }

        while (q --) {
            char c;
            int l, r, del;
            scanf(" %c", &c);
            if (c == 'C') {
                scanf("%d%d%d", &l, &r, &del);
                // 差分实现区间修改
                modify(treesum0, l, -del * (l - 1));
                modify(treesum0, r + 1, del * r);
                modify(treesum1, l, del);
                modify(treesum1, r + 1, -del);
            } else {
                scanf("%d%d", &l, &r);
                long long ans = a[r] - a[l - 1];
                ans += query(treesum0, r) - query(treesum0, l - 1);
                ans += r * query(treesum1, r) - (l - 1) * query(treesum1, l - 1);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
