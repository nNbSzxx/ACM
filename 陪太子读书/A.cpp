#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
int n;
string s;

int main()
{
    while (cin >> n) {

        cin >> s;

        char last = s[0];
        int cnt = 1;
        int maxx = -1;
        for (int i = 1; i < n; i ++) {
            if (s[i] != last) {
                maxx = max(maxx, cnt);
                cnt = 1;
                last = s[i];
            } else {
                ++ cnt;
            }
        }
        maxx = max(maxx, cnt);

        int ans = 0;
        cnt = 1;
        last = s[0];
        for (int i = 1; i < n; i ++) {
            if (s[i] != last) {
                if (cnt == maxx) {
                    ++ ans;
                }
                cnt = 1;
                last = s[i];
            } else {
                ++ cnt;
            }
        }
        if (cnt == maxx) {
            ++ ans;
        }
        printf("%d\n", ans);

        cnt = 1;
        last = s[0];
        int lastid = 0;
        for (int i = 1; i < n; i ++) {
            if (s[i] != last) {
                if (cnt == maxx) {
                    for (int j = lastid; j < i; j ++) {
                        printf("%c", s[j]);
                    }
                    puts("");
                }
                cnt = 1;
                last = s[i];
                lastid = i;
            } else {
                ++ cnt;
            }
        }
        if (cnt == maxx) {
            for (int j = lastid; j < n; j ++) {
                printf("%c", s[j]);
            }
            puts("");
        }
    }
    return 0;
}
