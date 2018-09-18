#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <climits>
using namespace std;
const int MAX = 5e5 + 10;
const int OK = 0;
const int IM = 1;
const int UN = 2;

long long n, m;
int s, q;
int cnt;
long long base;
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
    return x < base ? x + m : x;
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
    base = nd[1].b;
    long long b = nd[1].b;
    long long e = getid(nd[1].e);
    int flag = OK;
    if (cnt == 0) {
        flag = UN;
    }
    for (int i = 2; i <= cnt; i ++) {
        long long l = getid(nd[i].b);
        long long r = getid(nd[i].e);

        if (in(b, e, l)) {
            if (r < l) {
                flag = IM;
                break;
            }
            if (in(b, e, r)) {
                continue;
            } else {
                e = r;
            }
        } else {
            base = nd[i].b;
            b = getid(nd[i].b);
            e = getid(nd[i].e);
            break;
        }

    }
    if (flag == OK && e - b + 1 < m) {
        flag = UN;
    }

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
        if (i < 1 || i > n || j < 1 || j > m) {
            i = j = 0;
        }
        //printf("%lld %lld\n", i, j);
        ans ^= i;
        ans ^= j;

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

