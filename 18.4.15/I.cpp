#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n, joke[MAX], l[MAX];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &joke[i]);
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &l[i]);
        }
        int flag = 0;
        int last = -1;
        int maxx = -1;
        int secmaxx = -1;
        int isable;
        for (int i = 1; i <= n; i ++) {
            if (joke[i] == -1) continue;
            if (flag == 0) {
                if (l[i] <= maxx) {
                    flag ++;
                    if (l[i] <= secmaxx) {
                        // isable = 0;
                    } else {
                        // isable = 1;
                        maxx = l[i];
                    }
                }
                if (l[i] > maxx) {
                    secmaxx = maxx;
                    maxx = l[i];
                } else if (l[i] > secmaxx) {
                    secmaxx = l[i];
                }
                last = l[i];
            } else if (flag == 1) {
                /*
                if (l[i] <= maxx && l[i] <= secmaxx) {
                    flag ++;
                    break;
                } else if (!isable && l[i] <= maxx) {
                    flag ++;
                    break;
                }
                */
                if (l[i] <= maxx) {
                    ++ flag;
                    break;
                }
                if (l[i] > maxx) {
                    secmaxx = maxx;
                    maxx = l[i];
                } else if (l[i] > secmaxx) {
                    secmaxx = l[i];
                }
            }
            //printf("%d %d\n", maxx, secmaxx);
            if (flag >= 2) break;
        }
        if (!(flag >= 2)) {
            puts("#laughing_arjun");
        } else {
            puts("#itsnot_arjun");
        }
    }

}
