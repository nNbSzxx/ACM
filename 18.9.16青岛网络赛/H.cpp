#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 10;
char s[MAX];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf(" %s", s + 1);
        long long sum = 0;
        int n = strlen(s + 1);
        if (s[1] == '1') {
            sum += n;
        } else {
            sum += 2 * n;
        }
        for (int i = 2; i <= n; i ++) {
            long long l = i;
            long long r = n - i + 1;
            if (s[i - 1] != s[i]) {
                if (s[i] == '1') {
                    sum += l * r;
                } else {
                    sum += (l - 1) * r + 2 * r;
                }
            } else {
                if (s[i] == '0') {
                    sum += l * r * 2LL;
                } else {
                    sum += (l - 1) * r * 2LL + 1 * r;
                }
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
