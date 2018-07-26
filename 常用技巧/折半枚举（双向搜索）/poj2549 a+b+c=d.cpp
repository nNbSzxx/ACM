#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1e3 + 10;
const int NO_SOLUTION = -536870911 - 10;
int n;
int a[MAX];
struct Node {
    int sum;
    int i, j;
    Node(int ss, int ii, int jj) : sum(ss), i(ii), j(jj) {}

    bool operator<(const Node& rhs) const {
        return this -> sum < rhs.sum;
    }
};
vector<Node> v1, v2;

bool check(const Node& n1, const Node& n2)
{
    return (n1.i != n2.i &&
            n1.i != n2.j &&
            n1.j != n2.i &&
            n1.j != n2.j);
}

int main()
{
    while (~scanf("%d", &n), n) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        v1.clear();
        v2.clear();
        for (int i = 1; i < n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                v1.push_back(Node(a[i] + a[j], i, j));
            }
        }
        for (int i = 1; i < n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                v2.push_back(Node(a[j] - a[i], i, j));
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int ans = NO_SOLUTION;
        for (int i = 0; i < v1.size(); i ++) {
            int id = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
            for (; v2[id].sum == v1[i].sum; ++ id) {
                if (check(v1[i], v2[id])) {
                    ans = max(ans, a[v2[id].j]);
                }
            }
        }

        if (ans == NO_SOLUTION) {
            puts("no solution");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
