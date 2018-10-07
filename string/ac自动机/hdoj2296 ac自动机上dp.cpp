#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXM = 105;
const int MAXL = 15;
const int MAX = MAXM * MAXL;

struct acm {
    int tot = MAX - 1;
    int trie[MAX][26], fail[MAX], val[MAX];
    queue<int> q;

    void init() {
        memset(fail, 0, sizeof fail);
        memset(val, 0, sizeof val);
        for (int i = 0; i <= tot; i ++) {
            for (int j = 0; j < 26; j ++) {
                trie[i][j] = 0;
            }
        }
        fail[0] = 0;
        tot = 0;
    }
    void add(char *s, int len, int v) {
        int x = 0;
        for (int i = 0; i < len; i ++) {
            int id = s[i] - 'a';
            if (!trie[x][id]) {
                trie[x][id] = ++ tot;
            }
            x = trie[x][id];
        }
        val[x] = v;
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
            if (val[fail[now]]) {
                val[now] += val[fail[now]];
            }
            for (int i = 0; i < 26; i ++) {
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

const int INF = 0x3f3f3f3f;
int n, m, h[MAXM];
char s[MAXM][MAXL];
int dp[55][MAX];
string path[55][MAX];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i ++) {
            scanf(" %s", s[i]);
        }
        for (int i = 1; i <= m; i ++) {
            scanf("%d", &h[i]);
        }
        ac.init();
        for (int i = 1; i <= m; i ++) {
            ac.add(s[i], strlen(s[i]), h[i]);
        }
        //puts("111111111111111");
        ac.makefail();
        //puts("!!!!!!!!!!!");
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= ac.tot; j ++) {
                dp[i][j] = -INF;
            }
        }
        dp[0][0] = 0;
        path[0][0] = "";
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= ac.tot; j ++) {
                if (dp[i][j] < 0) {
                    continue;
                }
                for (int k = 0; k < 26; k ++) {
                    int x = ac.trie[j][k];
                    if (dp[i + 1][x] < dp[i][j] + ac.val[x]) {
                        dp[i + 1][x] = dp[i][j] + ac.val[x];
                        path[i + 1][x] = path[i][j] + char('a' + k);
                    } else if (dp[i + 1][x] == dp[i][j] + ac.val[x]) {
                        string str = path[i][j] + char('a' + k);
                        if (str < path[i + 1][x]) {
                            path[i + 1][x] = str;
                        }
                    }
                }
            }
        }
        int maxx = -INF;
        string str = "";
        int l = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= ac.tot; j ++) {
                if (dp[i][j] > maxx || (i == l && dp[i][j] == maxx && str > path[i][j])) {
                    str = path[i][j];
                    maxx = dp[i][j];
                    l = i;
                }
            }
        }
        if (maxx == 0) {
            str = "";
        }
        cout << str << endl;
    }

    return 0;
}
