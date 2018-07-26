#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
const int  MAX = 105;
struct Node {
    int l, r, len;
} node[MAX];

bool cmp(const Node& lhs, const Node& rhs)
{
    return lhs.len < rhs.len;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> node[i].l >> node[i].r;
        node[i].len = node[i].r - node[i].l;
    }

    sort(node, node + n, cmp);
    int ans = node[0].len;
    for (int i = ans; i >= 0; i ++) {
        for (int j = 0; j < n; j ++) {
            if
        }
    }



    cout << ans << endl;
    return 0;
}
