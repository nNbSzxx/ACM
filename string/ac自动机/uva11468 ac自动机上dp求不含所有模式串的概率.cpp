#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXK = 25;
const int MAXL = 25;
const int MAXN = 110;
const int MAXC = 26 + 26 + 10;
const int MAX = MAXK * MAXL;
const double EPS = 1e-8;

struct acm {
    int tot = MAX - 1;
    int trie[MAX][MAXC], fail[MAX], match[MAX];
    queue<int> q;
    void init() {
        memset(fail, 0, sizeof(int) * (tot + 1));
        memset(match, 0, sizeof(int) * (tot + 1));
        for (int i = 0; i <= tot; i ++) {
            for (int j = 0; j < MAXC; j ++) {
                trie[i][j] = 0;
            }
        }
        fail[0] = 0;
        tot = 0;
    }
    int getid(char c) {
        if (c >= '0' && c <= '9') {
            return c - '0';
        } else if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 10;
        } else {
            return c - 'a' + 36;
        }
    }
    void add(char *s, int len) {
        int x = 0;
        for (int i = 0; i < len; i ++) {
            int id = getid(s[i]);
            if (!trie[x][id]) {
                trie[x][id] = ++ tot;
            }
            x = trie[x][id];
        }
        match[x] = 1;
    }
    int getfail(int x, int k) {
        if (trie[x][k]) return trie[x][k];
        if (x == 0) return 0;
        return getfail(fail[x], k);
    }
    void makefail() {
        q.push(0);
        while (!q.empty()) {
            int now = q.front(); q.pop();
            if (match[fail[now]]) {
                match[now] = 1;
            }
            for (int i = 0; i < MAXC; i ++) {
                if (trie[now][i]) {
                    if (now == 0) {
                        fail[trie[now][i]] = 0;
                    } else {
                        fail[trie[now][i]] = getfail(fail[now], i);
                    }
                    q.push(trie[now][i]);
                } else {
                    trie[now][i] = trie[fail[now]][i];
                }
            }
        }
    }
} ac;


int n, m, l;
double p[MAXC];
double dp[MAXN][MAX];

int main()
{
    int t, tc = 1;
    scanf("%d", &t);
    while (t --) {
        ac.init();
        scanf("%d", &m);
        char s[MAXL];
        for (int i = 1; i <= m; i ++) {
            scanf(" %s", s);
            ac.add(s, strlen(s));
        }
        ac.makefail();

        scanf("%d", &n);
        for (int i = 0; i < MAXC; i ++) {
            p[i] = 0;
        }
        //printf("%lf\n", p[0]);
        char c;
        double d;
        for (int i = 1; i <= n; i ++) {
            scanf(" %c%lf", &c, &d);
            p[ac.getid(c)] = d;
        }

        scanf("%d", &l);

        for (int i = 0; i <= l; i ++) {
            for (int j = 0; j <= ac.tot; j ++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 0; i < l; i ++) {
            for (int j = 0; j <= ac.tot; j ++) {
                if (dp[i][j] == 0) {
                    continue;
                }
                for (int k = 0; k < MAXC; k ++) {
                    if (p[k] == 0) {
                        continue;
                    }
                    int x = ac.trie[j][k];
                    if (ac.match[x]) {
                        continue;
                    }
                    dp[i + 1][x] += dp[i][j] * p[k];
                }
            }
        }
        double ans = 0;
        for (int i = 0; i <= ac.tot; i ++) {
            if (!ac.match[i]) {
                ans += dp[l][i];
            }
        }
        printf("Case #%d: %.6f\n", tc ++, ans);
    }
    return 0;
}
