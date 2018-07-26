#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
const double PRE = 1e-52;
const int  MAX =1e5 + 10;
struct Node {
    int k, b;
    long double loc;
} node[MAX];

bool cmp(const Node& lhs, const Node& rhs)
{
    return lhs.loc < rhs.loc;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> node[i].k >> node[i].b;
        if (node[i].k == 0) {
            i --;
            n --;
        } else {
            node[i].loc = - (long double)node[i].b / node[i].k;
        }
    }
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    sort(node, node + n, cmp);
    int ans = 0;
    for (int i = 0; i < n - 1; i ++) {
        if (node[i + 1].loc - node[i].loc < PRE) {
            ;
        } else {
            ++ ans;
        }
    }
    ans ++;

    cout << ans << endl;
    return 0;
}
