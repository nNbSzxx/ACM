#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX = 5e4 + 10;
int n;
int w[MAX], h[MAX];
int l[MAX], r[MAX];
int sumw[MAX];
stack<int> s;

int main()
{
    while (~scanf("%d", &n), n != -1) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d%d", &w[i], &h[i]);
        }
        sumw[0] = 0;
        for (int i = 1; i <= n; i ++) {
            sumw[i] = sumw[i - 1] + w[i];
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = 1; i <= n; i ++) {
            while (!s.empty() && h[s.top()] >= h[i]) {
                s.pop();
            }
            l[i] = s.empty() ? 1 : s.top() + 1;
            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }
        for (int i = n; i >= 1; i --) {
            while (!s.empty() && h[s.top()] >= h[i]) {
                s.pop();
            }
            r[i] = s.empty() ? n : s.top() - 1;
            s.push(i);
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            ans = max(ans, h[i] * (sumw[r[i]] - sumw[l[i] - 1]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
