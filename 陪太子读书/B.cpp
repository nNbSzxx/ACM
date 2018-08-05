#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int k, n, m;
char s[15];
int main()
{
    while (~scanf("%d%d%d", &k, &n, &m)) {
        int cntm = 0, cntnm = 0;
        for (int i = 1; i <= k; i ++) {
            scanf(" %s", s);
            if (!strcmp(s, "Mars")) {
                ++ cntm;
            } else {
                ++ cntnm;
            }
        }
        int human = n - cntm;
        human = max(human, 0);
        int mars = m - cntnm;
        int ans = max(human + mars, 0);
        printf("%d\n", ans);
    }
    return 0;
}
