#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 5e5 + 10;
const int OK = 0;
const int IM = 1;
const int UN = 2;

long long n, m;
int s, q;
int cnt;
struct node {
    long long b, e;
} nd[MAX];

bool cmp(const node& n1, const node& n2)
{
    return n1.b < n2.b;
}

bool in(long long l, long long r, long long x)
{
    return l <= x && x <= r;
}

long long getid(long long x)
{
    return x < nd[1].b ? x + m : x;
}

int main()
{
    scanf("%lld%lld%d%d", &n, &m, &s, &q);
    cnt = 0;
    for (int i = 1; i <= s; i ++) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        -- a; -- b;
        if (a == b) {
            continue;
        }
        ++ cnt;
        nd[cnt].b = a % m;
        nd[cnt].e = b % m;
    }
    sort(nd + 1, nd + 1 + cnt, cmp);
    long long b = nd[1].b;
    long long e = getid(nd[1].e);
    int flag = OK;
    if (cnt == 0) {
        flag = UN;
    }
    for (int i = 2; i <= cnt; i ++) {
        long long l = getid(nd[i].b);
        long long r = getid(nd[i].e);
        if (r < l) {
            flag = IM;
            break;
        }
        if (in(b, e, l)) {
            if (in(b, e, r)) {
                continue;
            } else {
                e = r;
            }
        } else {
            flag = UN;
            break;
        }
    }
    if (e - b + 1 < m) {
        flag = UN;
    }

    bool zerostart = (b == 0);
    long long maxnum = zerostart ? (n * m) : ((n - 1) * m + b - 1);
    long long ans = 0;
    //printf("b, e: %lld %lld\n", b, e);
    //printf("max:%lld\n", maxnum);
    while (q --) {
        long long x;
        scanf("%lld", &x);
        if (flag != OK) {
            continue;
        }
        -- x;
        if (maxnum < 0 || x <= maxnum) {
            long long i = (x / m);
            long long j = (x % m);
            //printf("%lld %lld\n", i, j);
            j = j + ((b == 0) ? (0) : (m - b));
            //printf("%lld %lld\n", i, j);
            if (j >= m) {
                j -= m;
                i += 1;
            }
            ++ i;
            ++ j;
            //printf("%lld %lld\n", i, j);
            ans ^= i;
            ans ^= j;
        }
    }
    if (flag == IM) {
        puts("Impossible!");
    } else if (flag == UN) {
        puts("Uncertain!");
    } else {
        printf("%lld\n", ans);
    }
    return 0;
}

