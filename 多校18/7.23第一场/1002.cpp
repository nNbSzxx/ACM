#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
pair<int, int> p[MAX];
char s[MAX];
int n, ans;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2)
{
    int un = min(p1.second, p2.first);
    int ch = min(p1.first, p2.second);
    if (un > ch) {
        return true;
    } else if (un < ch) {
        return false;
    } else {
        return p1.second - p2.first > p2.second - p1.first;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf(" %s", s);
            int right = 0, left = 0;
            for (int j = 0; s[j] != '\0'; j ++) {
                if (s[j] == '(') {
                    ++ left;
                } else {
                    if (left != 0) {
                        ++ ans;
                        -- left;
                    } else {
                        ++ right;
                    }
                }
            }
            p[i] = make_pair(right, left);
        }

        sort(p + 1, p + 1 + n, cmp);
        int left = 0;
        for (int i = 1; i < n; i ++) {
            if (p[i].second < p[i + 1].first) {
                ans += p[i].second + min(left, p[i + 1].first - p[i].second);
                left = max(0, left - (p[i + 1].first - p[i].second));
            } else {
                ans += p[i + 1].first;
                left += p[i].second - p[i + 1].first;
            }
        }

        printf("%d\n", ans << 1);
    }
    return 0;
}
/*
999
3
))((((
))))(((
))))))((((
*/
