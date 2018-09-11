#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1e6 + 10;

int n, k;
int a[MAX];
struct node {
    int v, id;
    node(int vv, int idd) : v(vv), id(idd) {}
};
deque<node> maxq, minq;
int minn[MAX], maxx[MAX];

void popk(deque<node>& q, int cur, int k)
{
    while (!q.empty() && q.front().id + k <= cur) {
        q.pop_front();
    }
}

int main()
{
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
        }
        maxq.clear();
        minq.clear();

        for (int i = 1; i <= n; i ++) {
            while (!maxq.empty() && maxq.back().v <= a[i]) {
                maxq.pop_back();
            }
            maxq.push_back(node(a[i], i));
            while (!minq.empty() && minq.back().v >= a[i]) {
                minq.pop_back();
            }
            minq.push_back(node(a[i], i));
            popk(maxq, i, k);
            popk(minq, i, k);
            maxx[i] = maxq.front().v;
            minn[i] = minq.front().v;
        }
        for (int i = k; i <= n; i ++) {
            printf("%d ", minn[i]);
        }
        puts("");
        for (int i = k; i <= n; i ++) {
            printf("%d ", maxx[i]);
        }
        puts("");
    }
    return 0;
}
