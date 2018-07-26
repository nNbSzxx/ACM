#include <bits/stdc++.h>
using namespace std;
const int MAX = 130000;
map<int, int> mp;
vector<int> v, ans;

int main()
{
    int m, n, a;
    //freopen("1008.in", "r", stdin);
    while (~scanf("%d", &m)) {
        if (m == 1) {
            scanf("%d", &a);
            printf("%d\n", a);
            continue;
        }
        mp.clear();
        ans.clear();
        v.clear();
        for (int i = 1; i <= m; i ++) {
            scanf("%d", &a);
            mp[a] ++;
            v.push_back(a);
        }
        n = round((-1 + sqrt(1 + 8 * m)) / 2.0);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i ++) {
            if (!mp[v[i]]) {
                continue;
            }
            mp[v[i]] --;
            for (int j = 0; j < ans.size(); j ++) {
                mp[v[i] + ans[j]] --;
            }
            ans.push_back(v[i]);
            if (ans.size() >= n) {
                break;
            }
        }
        printf("%d\n", n);
        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); i ++) {
            printf(" %d", ans[i]);
        }
        puts("");
    }
}
