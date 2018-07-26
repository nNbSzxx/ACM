#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int ans;
const int SIZE = 26;

struct acm {
    static int tot;
    int trie[MAX][SIZE], fail[MAX], dep[MAX], vis[MAX], sum[MAX];
    void init() {
        //cout << tot << " tttttt" << endl;
        memset(fail, 0, sizeof(int) * (tot + 1));
        memset(dep, 0, sizeof(int) * (tot + 1));
        memset(vis, 0, sizeof(int) * (tot + 1));
        memset(sum, 0, sizeof(int) * (tot + 1));
        for (int i = 0; i <= tot; i ++) {
            for (int j = 0; j < SIZE; j ++) {
                trie[i][j] = 0;
            }
        }
        fail[0] = 0;
        tot = 0;
    }
    void insert(char *s, int len) {
        int x = 0;
        for (int i = 0; i < len; i ++) {
            int loc = s[i] - 'a';
            if (!trie[x][loc]) {
                trie[x][loc] = ++ tot;
                dep[tot] = i + 1;
                //cout << dep[tot] << " bbbb" <<endl;
                //fail[tot] = 0;
            }
            x = trie[x][loc];
            if (i == len - 1) {
                ++ sum[x];
            }
        }
    }
    int getfail(int x, int k) {
        if (trie[x][k]) return trie[x][k];
        if (x == 0) return 0;
        return getfail(fail[x], k);
    }
    void makefail() {
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (int i = 0; i < SIZE; i ++) {
                if (trie[now][i]) {
                    q.push(trie[now][i]);
                    if (now == 0) {
                        fail[trie[now][i]] = 0;
                    } else {
                        fail[trie[now][i]] = getfail(fail[now], i);
                        //cout << now << " " << fail[trie[now][i]] << endl;
                    }
                }
            }
        }
    }
    void query(char *s, int len, int mode) {
        if (mode == 0) {
            memset(vis, 0, sizeof vis);
        }
        int x = 0;
        for (int i = 0; i < len; i ++) {
            int id = s[i] - 'a';
            while (x && !trie[x][id]) x = fail[x];
            x = trie[x][id];
            int temp = x;
            while (temp) {
                if (mode == 0) {
                    vis[temp] = 1;
                    //cout << dep[temp] << " dddd" <<endl;
                } else  {
                    if (vis[temp])
                        ans = max(ans, dep[temp]);
                        //cout << dep[temp] << " " << i << " aa" << endl;
                }
                temp = fail[temp];
            }
        }
    }
} ac;
int acm::tot = MAX - 1;

char s[MAX * 2];
struct pos {
    char *st;
    int len;
} p[MAX];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        ac.init();
        int n;
        scanf("%d", &n);
        int now = 0;
        for (int i = 1; i <= n; i ++) {
            scanf(" %s", s + now);
            p[i].st = s + now;
            int l = strlen(s + now);
            //cout << l << " llll" << endl;
            p[i].len = l;
            ac.insert(s + now, l);
            now += l + 1;
        }
        ac.makefail();
        int m;
        scanf("%d", &m);
        int x, y;
        for (int i = 1; i <= m; i ++) {
            ans = 0;
            scanf("%d%d", &x, &y);
            //cout << p[x].len << " " << p[y].len <<endl;
            ac.query(p[x].st, p[x].len, 0);
            ac.query(p[y].st, p[y].len, 1);
            printf("%d\n", ans);
        }
    }
}
