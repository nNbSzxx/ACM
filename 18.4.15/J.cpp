#include <bits/stdc++.h>
using namespace std;
const int MAX = 30;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int now = 0, a, flag = 0;
        for (int i = 0; i < MAX; i ++) {
            scanf("%d", &a);
            if (a == 1) {
                ++ now;
                if (now > 5) {
                    flag = 1;

                }
            } else {
                now = 0;
            }
        }
        if (flag) {
            puts("#coderlifematters");
        } else {
            puts("#allcodersarefun");
        }
    }
    return 0;
}
