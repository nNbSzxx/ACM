#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
const int MAX = 3e5 + 10;
int k, n;
struct interval {
    int l, r, id, len;
    bool operator< (const interval& rhs) const {
        return r > rhs.r;
    }
} inter[MAX];

bool cmp(const interval& lhs, const interval& rhs)
{
    return (lhs.l < rhs.l);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> inter[i].l >> inter[i].r ;
        inter[i].id = i;
        inter[i].len = inter[i].r - inter[i].l + 1;
    }
    sort(inter, inter + n, cmp);
    priority_queue<interval> q;

    for (int i = 0; i < k; i ++) {
        q.push(inter[i]);
    }

    int len = q.top().r - inter[k - 1].l + 1;
    len = max(0, len);
    int l = inter[k - 1].l;
    int r = q.top().r;
    for (int i = k; i < n; i ++) {
        interval inte = q.top();
        q.pop();
        q.push(inter[i]);
        int nlen = q.top().r - inter[i].l + 1;
        if (nlen > len) {
            len = nlen;
            l = inter[i].l;
            r = q.top().r;
        }
    }
    cout << len << endl;
    int flag = 0;
    int sum = 0;
    for (int i = 0; i < n ; i ++) {
        if (sum == k) break;
        if (inter[i].l <= l && inter[i].r >= r) {
            sum ++;
            if (flag) {
                cout << " ";
            }
            cout << inter[i].id + 1;
            flag = 1;
        }
    }
    cout << endl;

    return 0;
}
