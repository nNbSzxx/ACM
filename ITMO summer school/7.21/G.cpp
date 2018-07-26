#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX = 220;
int n, m, t;
char a[MAX], b[MAX];
int s[2 * MAX * MAX];

int gcd(int x, int y)
{
    int r;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    scanf("%d", &t);
    while (t --) {
        scanf(" %s %s", a, b);
        scanf("%d", &n);
        int len1 = strlen(a);
        int len2 = strlen(b);
//        cout << len1 << endl << len2 << endl;
        int l = len1 / gcd(len1, len2) * len2;
        int r = 0;
        for (int i = l * 2 + 10; i >= 0; i --) {
            s[i] = (a[i % len1] + b[i % len2] + r - '0' * 2) % 10;
            r = (a[i % len1] + b[i % len2] + r - '0' * 2) / 10;
            //cout << i << " " << i % len1 << " " << i % len2 << endl;
        }
        long long loc = -1;
        for (int i = l * 2 + 10; i >= 0; i --) {
            if (s[i] != 9) {
                loc = i;
                break;
            }
        }
        if (loc != -1)
        	s[loc] ++;
        for (int i = loc + 1; i <= l * 2 + 10; i ++) {
            s[i] = 0;
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%lld", &loc);
            printf("%d", s[(loc - 1) % l]);
        }
        printf("\n");
    }
    return 0;
}
