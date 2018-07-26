#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
long long w, h;

int check(int x, int y, int z)
{
    int ww, hh;
    ww = x + 2 * y;
    hh = 2 * y + 2 * z;
    if ((ww <= w && hh <= h) || (ww <= h && hh <= w))
        return 1;
    ww = 3 * x + y + z;
    hh = y + z;
    if ((ww <= w && hh <= h) || (ww <= h && hh <= w))
        return 1;
    return 0;
}

int main()
{
    scanf("%d%d%d%d%d", &a, &b, &c, &w, &h);
    int ans =
        check(a, b, c) + check(a, c, b) +
        check(b, a, c) + check(b, c, a) +
        check(c, a, b) + check(c, b, a);
    if (ans) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
