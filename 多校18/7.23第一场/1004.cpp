#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
set<int> s;
int n, m, t;
pair<int, int> seg[MAX];
int ans[MAX];

int main()
{
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        int maxx = 0;
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d", &seg[i].first, &seg[i].second);
            maxx = max(maxx, seg[i].second - seg[i].first + 1);
        }
        sort(seg + 1, seg + 1 + m);
        s.clear();
        for (int i = 1; i <= maxx + 1; i ++) {
            s.insert(i);
        }
        int cur = 1;
        int lst = 1;
        for (int i = 1; i <= m; i ++) {
            int l = seg[i].first;
            int r = seg[i].second;

            for (int j = lst; j < min(cur, l); j ++) {
                s.insert(ans[j]);
            }
            while (cur < l) {
                ans[cur] = 1;
                ++ cur;
            }
            while (cur <= r) {
                ans[cur] = *s.begin();
                s.erase(s.begin());
                ++ cur;
            }
            lst = l;
        }
        while (cur <= n) {
            ans[cur] = 1;
            ++ cur;
        }
        for (int i = 1; i <= n; i ++) {
            printf(i==n?"%d\n":"%d ", ans[i]);
        }
    }
    return 0;
}
