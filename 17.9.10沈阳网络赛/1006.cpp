#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e4 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int v[MAX], n;

long long findMin(int x, long long now, int last, long long a, long long b);
long long findMax(int x, long long now, int last, long long a, long long b)
{
    if (x > n) {
        return now;
    }
    long long ret = -INF;if (x + last - 1 <= n) {
        ret = max(ret, findMin(x + last, now + v[x + last - 1] - v[x - 1], last, a, b));
        //cout << "max " << x << " " << ret << endl;
        if (ret >= b) return ret;
        a = max(a, ret);
    }
    if (x + last <= n) {
        ret = max(ret, findMin(x + last + 1, now + v[x + last] - v[x - 1], last + 1, a, b));
        //cout << "max " << x << " " << ret << endl;
        if (ret >= b) return ret;
        a = max(a, ret);
    }

    if (ret == -INF) ret = now;
    return ret;
}

long long findMin(int x, long long now, int last, long long a, long long b)
{
    if (x > n) {
        return now;
    }
    long long ret = INF;if (x + last - 1 <= n) {
        ret = min(ret, findMax(x + last, now - v[x + last - 1] + v[x - 1], last, a, b));
        //cout << "min " << x << " " << ret << endl;
        if (ret <= a) return ret;
        b = min(b, ret);
    }
    if (x + last <= n) {
        ret = min(ret, findMax(x + last + 1, now - v[x + last] + v[x - 1], last + 1, a, b));
        //cout << "min " << x << " " << ret << endl;
        if (ret <= a) return ret;
        b = min(b, ret);
    }

    if (ret == INF) ret = now;
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &v[i]);
            v[i] += v[i - 1];
        }
        long long ans = findMax(1, 0, 1, -INF, INF);
        printf("%lld\n", ans);
    }
}
