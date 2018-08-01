#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 10;
int w[MAX];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &w[i]);
        }
        int ans = floor(sqrt(abs(w[1] - w[n])) + 0.005);
        printf("%d\n", ans);
    }
    return 0;
}
