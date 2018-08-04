#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const int MAX = 4e4 + 10;
struct cir {
    double r;
    double x, y;
    int id;
} c[MAX];
int n;
pair<double, int> events[MAX << 1];
set<pair<double, int> > scan;
vector<int> ans;

bool inside(const cir& c1, const cir& c2)
{
    double dx = c1.x - c2.x;
    double dy = c1.y - c2.y;
    return dx * dx + dy * dy <= c2.r * c2.r;
}

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i ++) {
            scanf("%lf%lf%lf", &c[i].r, &c[i].x, &c[i].y);
            c[i].id = i;
            events[i * 2] = make_pair(-c[i].r + c[i].x, i);
            events[i * 2 + 1] = make_pair(c[i].r + c[i].x, i + n);
        }
        sort(events, events + 2 * n);
        scan.clear();
        ans.clear();
        for (int i = 0; i < 2 * n; i ++) {
            int id = events[i].second % n;
            if (events[i].second < n) {
                set<pair<double, int> >::iterator it = scan.lower_bound(make_pair(c[id].y, id));
                if (it != scan.end() && inside(c[id], c[it -> second])) {
                    continue;
                }
                if (it != scan.begin() && inside(c[id], c[(--it) -> second])) {
                    continue;
                }
                ans.push_back(id);
                scan.insert(make_pair(c[id].y, id));
            } else {
                scan.erase(make_pair(c[id].y, id));
            }
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i ++) {
            printf((i == (ans.size() - 1))?"%d\n":"%d ", ans[i] + 1);
        }
    }
    return 0;
}
