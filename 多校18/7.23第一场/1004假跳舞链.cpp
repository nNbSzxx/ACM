#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 1e5 + 10;
pair<int, int> seg[MAXM];
int n, m;
int L[MAXN], R[MAXN];
int ans[MAXN];
void init() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &seg[i].first, &seg[i].second);
    for (int i = 0; i <= n + 1; ++i) {
        L[i] = i - 1;
        R[i] = i + 1;
    }
    memset(ans, 0, sizeof ans);
}
void enable(int p) {
    L[R[p]] = p;
    R[L[p]] = p;
}
void del(int p) {
    R[L[p]] = R[p];
    L[R[p]] = L[p];
}
void solve() {
    int pl = 1;
    int maxr = 0;
    for (int i = 0; i < m; ++i) {
        //printf("seg: %d %d\n", seg[i].first, seg[i].second);
        int nowl = seg[i].first;
        int nowr = seg[i].second;
        if (nowr <= maxr) continue;
        for (int j = maxr + 1; j < nowl; ++j) {
            ans[j] = 1;
            // del(1);
        }
        for (int j = nowl - 1; j >= pl; --j) enable(ans[j]), printf("Enable: %d\n", ans[j]);
        pl = nowl;
        for (int j = max(nowl, maxr + 1); j <= nowr; ++j) {
            ans[j] = R[0];
            del(ans[j]);
            printf("Del: %d\n", ans[j]);
        }
        maxr = max(maxr, nowr);
    }
    for (int i = maxr + 1; i <= n; ++i)
        ans[i] = 1;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        sort(seg, seg + m);
        solve();
        for (int i = 1; i <= n; ++i)
            printf(i == n ? "%d\n" : "%d ", ans[i]);
    }
    return 0;
}
/*
1
10 3
2 5
4 8
7 10
*/
