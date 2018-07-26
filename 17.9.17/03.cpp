#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n, ans;
char s[MAX];


inline char nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? '@' : *p1++;
}
int over;
inline int _read() {
    char ch = nc();
    int ret = 0;
    int len = 0;
    while(!(ch >= 'a' && ch <= 'z') && !(ch >= '0' && ch <= '9')) {
        ch = nc();
        if(ch == '@') { over = 1; break; }
    }
    while(ch >= '0' && ch <= '9') {
        ret = ret * 10 + ch - '0', ch = nc();
        if(ch == '@') { over = 1; break; }
    }
    if (ret != 0) return ret;
    while(ch >= 'a' && ch <= 'z') {
        s[len ++] = ch, ch = nc();
        if(ch == '@') { over = 1; break; }
    }
    s[len] = '\0';
    return ret;
}


struct acm {
	static int tot;
	int trie[MAX][26], sum[MAX], fail[MAX];
	void init() {
		memset(sum, 0, sizeof(int) * (tot + 1));
		memset(fail, 0, sizeof(int) * (tot + 1));
		for (int i = 0; i <= tot; i ++) {
			for (int j = 0; j < 26; j ++) {
				trie[i][j] = 0;
			}
		}
		fail[0] = 0;
		tot = 0;
	}
	void add(char *s, int len) {
		int x = 0;
		for (int i = 0; i < len; i ++) {
			int id = s[i] - 'a';
			if (!trie[x][id]) {
				trie[x][id] = ++ tot;
			}
			x = trie[x][id];
			if (i == len - 1) {
				sum[x] ++;
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
			while (x && !trie[x][id]) x = fail[x];
			x = trie[x][id];
			int temp = x;
			while (temp) {
				if (sum[temp]) {
					ans += sum[temp];
					sum[temp] = 0;
				}
				temp = fail[temp];
			}
		}
	}
} ac;
int acm::tot = MAX - 1;

int main()
{
    //freopen("03.in", "r", stdin);
	int t;
	t = _read();
	while (t --) {
        n = _read();
        ac.init();
        int maxlen = -1;
        int len, flag;
        char maxs[MAX];
        for (int i = 1; i <= n; i ++) {
            //scanf(" %s", s);
            _read();
            len = strlen(s);
            if (len > maxlen) {
                strcpy(maxs, s);
                maxlen = len;
                flag = 0;
            } else if (len == maxlen) {
                if (strcmp(maxs, s)) {
                    flag = 1;
                }
            }
            ac.add(s, len);
        }
        if (flag == 1) {
            puts("No");
            continue;
        }
		ans = 0;
		ac.makefail();
		ac.match(maxs, maxlen);
		//printf("%d\n", ans);
		//puts(maxs);
		if (ans == n) {
            puts(maxs);
		} else {
            puts("No");
		}
	}
	return 0;
}
