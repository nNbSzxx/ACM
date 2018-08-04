#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
char s[MAX];
int n, q;
int sum[27][MAX];

int main()
{
    int t, tc = 1;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &q);
        scanf(" %s", s + 1);
        for (char c = 'A'; c <= 'Z'; c ++) {
            sum[c - 'A'][0] = 0;
            for (int i = 1; i <= n; i ++) {
                sum[c - 'A'][i] = sum[c - 'A'][i - 1];
                if (s[i] == c) {
                    ++ sum[c - 'A'][i];
                }
            }
        }
        printf("Case #%d:\n", tc ++);
        while (q --) {
            int l, r;
            scanf("%d%d", &l, &r);
            int ans;
            for (char c = 'A'; c <= 'Z'; c ++) {
                int v = sum[c - 'A'][r] - sum[c - 'A'][l - 1];
                if (v != 0) {
                    printf("%d\n", v);
                    break;
                }
            }
        }
    }
    return 0;
}
