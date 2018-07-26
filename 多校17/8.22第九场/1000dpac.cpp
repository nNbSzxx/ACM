#include <bits/stdc++.h>
using namespace std;
char str[2510], pat[2510];
bool dp[2510][2510];
int rec[2510];

int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf(" %s %s", str, pat);
        int ls = strlen(str);
        int lp = strlen(pat);
        memset(dp, false, sizeof dp);
        memset(rec, 0, sizeof rec);
        dp[0][0] = true;
        for (int i = 1; i < lp; ++i)
            if (pat[i] == '*' && dp[0][i - 1]) dp[0][i + 1] = true;
        for (int i = 0; i < ls; ++i) {
            for (int j = 0; j < lp; ++j) {
                if (pat[j] == '.' || pat[j] == str[i]) dp[i + 1][j + 1] |= dp[i][j];
                if (pat[j] == '*') {
                    if (pat[j - 1] != str[i] && pat[j - 1] != '.')
                        dp[i + 1][j + 1] |= dp[i + 1][j - 1];
                    else {
                        dp[i + 1][j + 1] |= dp[i + 1][j] || dp[i + 1][j - 1];
                        if (dp[i + 1][j + 1]) continue;
                        else if (dp[i][j]) {
                            for (int k = i; k < ls; k ++) {
                                if (str[k] == str[i - 1]) {
                                    dp[k + 1][j + 1] = true;
                                } else {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (dp[ls][lp])
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
