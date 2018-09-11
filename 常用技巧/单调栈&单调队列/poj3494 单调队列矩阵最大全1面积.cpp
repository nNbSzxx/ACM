#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX = 2010;
int n, m;
int l[MAX], r[MAX], h[MAX];
int mat[MAX][MAX];
stack<int> s;

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                scanf("%d", &mat[i][j]);
            }
        }

        int ans = 0;
        memset(h, 0, sizeof h);
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (mat[i][j]) {
                    h[j] += 1;
                } else {
                    h[j] = 0;
                }
            }

            while (!s.empty()) {
                s.pop();
            }
            for (int j = 1; j <= m; j ++) {
                while (!s.empty() && h[s.top()] >= h[j]) {
                    s.pop();
                }
                l[j] = s.empty() ? 1 : s.top() + 1;
                s.push(j);
            }
            while (!s.empty()) {
                s.pop();
            }
            for (int j = m; j >= 1; j --) {
                while (!s.empty() && h[s.top()] >= h[j]) {
                    s.pop();
                }
                r[j] = s.empty() ? m : s.top() - 1;
                s.push(j);
            }
            for (int j = 1; j <= m; j ++) {
                ans = max(ans, h[j] * (r[j] - l[j] + 1));
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
