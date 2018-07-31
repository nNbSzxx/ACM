#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1e7 + 10;
int n, m, k, p, q, r, mod;
int a[MAX];
deque<pair<int, int> > qe;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        qe.clear();
        scanf("%d%d%d%d%d%d%d", &n, &m, &k, &p, &q, &r, &mod);
        long long anscnt = 0, ansmax = 0;
        for (int i = 1; i <= k; i ++) {
            scanf("%d", &a[i]);
        }
        for (int i = k + 1; i <= n; i ++) {
            a[i] = (1LL * p * a[i - 1] + 1LL * q * i + r) % mod;
        }
        for (int i = n; i > n - m + 1; i --) {
            while (!qe.empty() && a[i] >= qe.back().first) {
                qe.pop_back();
            }
            qe.push_back(make_pair(a[i], i));
        }
        for (int i = n - m + 1; i >= 1; i --) {
            while (!qe.empty() && a[i] >= qe.back().first) {
                qe.pop_back();
            }
            qe.push_back(make_pair(a[i], i));
            if (qe.front().second >= i + m) {
                qe.pop_front();
            }
            ansmax += i ^ qe.front().first;
            anscnt += i ^ qe.size();
        }
        printf("%lld %lld\n", ansmax, anscnt);
    }

    return 0;
}
