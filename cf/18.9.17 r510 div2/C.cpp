#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX = 2e5 + 10;
int n;
struct node {
    int v, id;
} a[MAX];
int vis[MAX];

bool cmp(const node& n1, const node& n2)
{
    if (n1.v != n2.v) {
        return n1.v < n2.v;
    } else {
        return n1.id < n2.id;
    }
}

int main()
{
    scanf("%d", &n);
    int zero = 0, neg = 0, pos = 0;
    int minn = 1e9 + 10, minnid = -1;
    int zeroid = -1;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i].v);
        a[i].id = i;
        if (a[i].v == 0) {
            ++ zero;
        } else if (a[i].v < 0) {
            ++ neg;
        } else {
            ++ pos;
        }
    }

    sort(a + 1, a + 1 + n, cmp);
    int maxneg = n;
    for (int i = 1; i <= n; i ++) {
        if (a[i].v >= 0) {
            maxneg = i - 1;
            break;
        }
    }

    int elinum = zero + (neg & 1);
    int lastid = a[maxneg + 1].id;
    for (int i = 2; i <= zero; i ++) {
        int curid = a[maxneg + i].id;
        printf("1 %d %d\n", lastid, curid);
        vis[lastid] = vis[curid] = 1;
        lastid = curid;
    }

    if (zero && (neg & 1)) {
        int curid = a[maxneg].id;
        printf("1 %d %d\n", lastid, curid);
        vis[lastid] = vis[curid] = 1;
        lastid = curid;
    } else if (!zero && (neg & 1)) {
        lastid = a[maxneg].id;
    }

    if (elinum && elinum != n) {
        printf("2 %d\n", lastid);
        vis[lastid] = 1;
    }

    int lasti = n + 1;
    for (int i = 1; i <= n; i ++) {
        int id = a[i].id;
        if (!vis[id]) {
            lasti = i;
            lastid = id;
            break;
        }
    }
    for (int i = lasti + 1; i <= n; i ++) {
        int curid = a[i].id;
        if (vis[curid]) {
            continue;
        }
        printf("1 %d %d\n", lastid, curid);
        lastid = curid;
    }

    return 0;
}
