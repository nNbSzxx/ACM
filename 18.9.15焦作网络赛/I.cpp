#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 100005;
const int MOD = 1e9 + 7;
char s[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        LL val = 0;
        for (int i = 0; s[i]; ++i)
            val = (val * 10 + (s[i] - '0')) % (MOD - 1);

    }
}
