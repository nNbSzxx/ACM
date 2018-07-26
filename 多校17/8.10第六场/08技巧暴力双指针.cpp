#include <bits/stdc++.h>
using namespace std;
const int MAX = 5050;

int main()
{
    //freopen("1008.in", "r", stdin);
    int t, m;
    char s[MAX];
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &m);
        scanf(" %s", s);
        int len = strlen(s);
        int ans = 0;
        for (int k = 1; k < len; k ++) {
            int h = k - 1, r = k;
            int i = h, j = r;
            int sum = 0;
            while (i >= 0 && j < len) {
                sum += abs(s[i --] - s[j ++]);
                while (sum > m) {
                    sum -= abs(s[h --] - s[r ++]);
                    //cout << h << " " << r << endl;
                }
                //cout << i << " " << j << " " << h << " " << r << endl;
                ans = max(ans, h - i);
            }
        }

        for (int k = 1; k < len - 1; k ++) {
            int h = k - 1, r = k + 1;
            int i = h, j = r;
            int sum = 0;
            while (i >= 0 && j < len) {
                sum += abs(s[i --] - s[j ++]);
                while (sum > m) {
                    sum -= abs(s[h --] - s[r ++]);
                }
                ans = max(ans, h - i);
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}
