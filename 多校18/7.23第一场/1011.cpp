#include <bits/stdc++.h>
using namespace std;
const int mod = 1440;

int main()
{
    int t;
    int h, m;
    char str[120];
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d %s", &h, &m, str);
        int sign = (str[3] == '+' ? 1 : -1);
        int i = 4;
        int find = false;
        int u = 0;
        int mu = 0;
        while (str[i] != '\0') {
            if (str[i] != '.') {
                if (!find) {
                    u = u * 10 + (str[i] - '0');
                } else {
                    mu = mu * 10 + (str[i] - '0');
                }
            } else if (str[i] == '.') {
                find = true;
            }
            ++ i;
        }
        u *= sign;
        mu *= sign;
        int minute = h * 60 + m;
        minute = (minute - 8 * 60 + mod) % mod;
        minute = (minute + u * 60 + mu * 6 + mod) % mod;
        printf("%02d:%02d\n", minute / 60, minute % 60);
    }
    return 0;
}
