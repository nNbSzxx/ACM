#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
int l[MAX], r[MAX];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &l[i], &r[i]);
    }
    sort(l + 1, l + 1 + n);
    sort(r + 1, r + 1 + n);
    long long ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += max(l[i], r[i]) + 1;
    }
    printf("%d\n", ans);
    return 0;
}
