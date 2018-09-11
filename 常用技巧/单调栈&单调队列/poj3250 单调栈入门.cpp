#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX = 8e4 + 10;
int h[MAX];
int n;
stack<int> s;

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &h[i]);
        }
        long long ans = 0;
        while (!s.empty()) {
            s.pop();
        }
        s.push(h[1]);
        for (int i = 2; i <= n; i ++) {
            while (!s.empty() && s.top() <= h[i]) {
                s.pop();
            }
            ans += s.size();
            s.push(h[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
