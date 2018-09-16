#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        int un = n - m;
        int b = m;
        int w = (m - 1) / (un + 1) + 1;
        w = min(w, b);
        printf("%d %d\n", b, w);
    }
    return 0;
}
