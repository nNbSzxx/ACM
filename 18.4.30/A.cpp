#include <bits/stdc++.h>
using namespace std;
const int MAXH = 24;
const int MAXM = 60;
const int MAXN = 30;
int h1[33], m1[33], h2[33], m2[33];
const int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3 ,7, 6};

int main()
{
    memset(h1, -1, sizeof h1);
    //memset(m1, -1, sizeof m1);
    for (int i = 0; i <= MAXN; i ++) {
        for (int hh = 0; hh < MAXH; hh ++) {
            for (int mm = 0; mm < MAXM; mm ++) {
                int fh = hh / 10;
                int lh = hh % 10;
                int fm = mm / 10;
                int lm = mm % 10;
                if (cost[fh] + cost[lh] + cost[fm] + cost[lm] == i) {
                    //if (h1[i] == -1) {
                        h1[i] = fh;
                        m1[i] = fm;
                        h2[i] = lh;
                        m2[i] = lm;
                    //}
                }
            }
        }
    }
    int i;
    freopen("alarm.in", "r", stdin);
    freopen("alarm.out", "w", stdout);
    scanf("%d", &i);
    if (h1[i] != -1)
        printf("%d%d:%d%d\n", h1[i], h2[i], m1[i], m2[i]);
    else
        puts("Impossible");
    return 0;
}
