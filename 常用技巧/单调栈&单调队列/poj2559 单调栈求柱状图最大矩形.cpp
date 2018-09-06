#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX = 1e5 + 10;

int n;
int h[MAX];
stack<int> s;
int l[MAX], r[MAX];

int main()
{
    while (~scanf("%d", &n), n) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &h[i]);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = 1; i <= n; i ++) {
            while (!s.empty()) {
                if (h[i] <= h[s.top()]) {
                    s.pop();
                } else {
                    break;
                }
            }
            if (s.empty()) {
                l[i] = 1;
            } else {
                l[i] = s.top() + 1;
            }
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n; i >= 1; i --) {
            while (!s.empty()) {
                if (h[i] <= h[s.top()]) {
                    s.pop();
                } else {
                    break;
                }
            }
            if (s.empty()) {
                r[i] = n;
            } else {
                r[i] = s.top() - 1;
            }
            s.push(i);
        }
        /*
        for (int i = 1; i <= n; i ++) {
            printf("%d %d\n", l[i], r[i]);
        }
        */
        long long ans = -1;
        for (int i = 1; i <= n; i ++) {
            ans = max(ans, 1LL * h[i] * (r[i] - l[i] + 1));
        }
        printf("%lld\n", ans);
    }


    return 0;
}
