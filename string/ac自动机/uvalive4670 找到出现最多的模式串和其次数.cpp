#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 155;
const int MAXL = 75;
const int MAX = MAXN * MAXL;
const int MAXS = 1e6 + 10;

struct acm {
    int tot = MAX - 1;
    int trie[MAX][26], fail[MAX], sid[MAX];
    queue<int> q;
    int cnt[MAXN];
    void init() {
        memset(fail, 0, sizeof(int) * (tot + 1));
        memset(sid, 0, sizeof(int) * (tot + 1));
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i <= tot; i ++) {
            for (int j = 0; j < 26; j ++) {
                trie[i][j] = 0;
            }
        }
        fail[0] = 0;
        tot = 0;
    }
    void add(char *s, int len, int tag) {
        int x = 0;
        for (int i = 0; i < len; i ++) {
            int id = s[i] - 'a';
            if (!trie[x][id]) {
                trie[x][id] = ++ tot;
            }
            x = trie[x][id];
        }
        sid[x] = tag;
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
            for (int i = 0; i < 26; i ++) {
                if (trie[now][i]) {
                    if (now == 0) {
                        fail[trie[now][i]] = 0;
                    } else {
                        fail[trie[now][i]] = getfail(fail[now], i);
                    }
                    q.push(trie[now][i]);
                }
            }
        }
    }
    void match(char *s, int len) {
        int x = 0;
        for (int i = 0; i < len; i ++) {
            int id = s[i] - 'a';
            while (x && !trie[x][id]) {
                x = fail[x];
            }
            x = trie[x][id];
            int temp = x;
            while (temp) {
                if (sid[temp]) {
                    cnt[sid[temp]] ++;
                }
                temp = fail[temp];
            }
        }
    }
} ac;

int n;
char s[MAXN][MAXL], tar[MAXS];

int main()
{
    while (~scanf("%d", &n), n) {
        ac.init();
        for (int i = 1; i <= n; i ++) {
            scanf(" %s", s[i]);
            ac.add(s[i], strlen(s[i]), i);
        }
        ac.makefail();
        scanf(" %s", tar);
        ac.match(tar, strlen(tar));
        int maxx = 0;
        for (int i = 1; i <= n; i ++) {
            maxx = max(maxx, ac.cnt[i]);
        }
        printf("%d\n", maxx);
        for (int i = 1; i <= n; i ++) {
            if (maxx == ac.cnt[i]) {
                puts(s[i]);
            }
        }
    }

    return 0;
}
