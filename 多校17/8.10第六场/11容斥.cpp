#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    //freopen("1011.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    int t, n;
    int a, b, c, ab, bc, ac, abc;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int ans = -1;
        while (n --) {
            scanf("%d%d%d%d%d%d%d", &a, &b, &c, &ab, &bc, &ac, &abc);
            int sum = a + b + c - ab - ac - bc + abc;
            ab -= abc;
            bc -= abc;
            ac -= abc;
            a -= abc;
            b -= abc;
            c -= abc;
            if (abc < 0 || ab < 0 || bc < 0 || ac < 0 || a < 0 || b < 0 || c < 0) {
                continue;
            }
            a -= ab + ac;
            b -= ab + bc;
            c -= ac + bc;
            if (a < 0 || b < 0 || c < 0) {
                continue;
            }
            ans = max(ans, sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}
