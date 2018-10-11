#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 2e5 + 10;

inline int read()
{
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}

struct edge {
    int v, nt;
} e[MAX];
int head[MAX], cnte;

void adde(int u, int v)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

struct acm {
	int tot;
	int trie[MAX][26], tag[MAX], fail[MAX], nd[MAX], fa[MAX];
	queue<int> q;
	void init() {
	    tot = MAX - 1;
		memset(tag, 0, sizeof(int) * (tot + 1));
		memset(fail, 0, sizeof(int) * (tot + 1));
		memset(nd, 0, sizeof nd);
		memset(fa, 0, sizeof fa);
		for (int i = 0; i <= tot; i ++) {
			for (int j = 0; j < 26; j ++) {
				trie[i][j] = 0;
			}
		}
		fail[0] = 0;
		tot = 0;
	}
	void add(char *s, int len, int k) {
		int x = 0;
		for (int i = 0; i < len; i ++) {
			int id = s[i] - 'a';
			if (!trie[x][id]) {
				trie[x][id] = ++ tot;
			}
			x = trie[x][id];
		}
		tag[x] = k;
		nd[k] = x;
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
						adde(0, trie[now][i]);
					} else {
						int f = getfail(fail[now], i);
						fail[trie[now][i]] = f;
						adde(f, trie[now][i]);
					}
					q.push(trie[now][i]);
				}
			}
		}
	}
} ac;

int in[MAX], out[MAX], idx;

void dfsFail(int x)
{
    in[x] = ++ idx;
    for (int i = head[x]; i != -1; i = e[i].nt) {
        dfsFail(e[i].v);
    }
    out[x] = idx;
}

int treesum[MAX];
inline int lowbit(int x)
{
    return x & (-x);
}
void modify(int x, int v)
{
    for (int i = x; i < MAX; i += lowbit(i)) {
        treesum[i] += v;
    }
}
int query(int x)
{
    if (x == 0) {
        return 0;
    }
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ret += treesum[i];
    }
    return ret;
}

vector<pair<int, int> > qu[MAX];
int ans[MAX];

void dfsTrie(int x)
{
    //printf("%d\n", x);
    modify(in[x], 1);
    if (ac.tag[x]) {
        // auto a : qu[ac.tag[x]]
        for (int i = 0; i < qu[ac.tag[x]].size(); i ++) {
            pair<int, int> a = qu[ac.tag[x]][i];
            //printf("%d %d\n", in[ac.nd[a.first]] - 1, out[ac.nd[a.first]]);
            ans[a.second] = - query(in[ac.nd[a.first]] - 1) + query(out[ac.nd[a.first]]);
        }
    }
    for (int i = 0; i < 26; i ++) {
        if (ac.trie[x][i]) {
            dfsTrie(ac.trie[x][i]);
        }
    }
    modify(in[x], -1);
}

char s[MAX], tmp[MAX];

int main()
{
    //freopen("testdata1.in", "r", stdin);
    scanf(" %s", s);
    int len = strlen(s);
    //printf("%d\n", len);
    int t = 0, cnt = 0, x = 0;
    ac.init();
    //puts("1111111111");
    for (int i = 0; i < len; i ++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            int id = s[i] - 'a';
            if (!ac.trie[x][id]) {
                ac.trie[x][id] = ++ ac.tot;
                ac.fa[ac.tot] = x;
            }
            x = ac.trie[x][id];
        } else if (s[i] == 'B') {
            x = ac.fa[x];
        } else {
            ++ cnt;
            ac.tag[x] = cnt;
            ac.nd[cnt] = x;
        }

    }
    //puts("!!!!!!!!!");
    memset(head, -1, sizeof head);
    cnte = 0;
    ac.makefail();

    idx = 0;
    dfsFail(0);

    //puts("!!!!!!!!!!!!!");
    int q;
    q = read();
    //printf("%d\n", q);
    for (int i = 1; i <= q; i ++) {
        int x, y;
        x = read();
        y = read();
        qu[y].push_back(make_pair(x, i));
    }
    memset(treesum, 0, sizeof treesum);
    //puts("before dfsTrie");
    //printf("%d\n", ac.tot);
    dfsTrie(0);
    //puts("!!!!!!!!!!!!!!!!!!!!!!11");
    for (int i = 1; i <= q; i ++) {
        printf("%d\n", ans[i]);
    }
    //printf("%d %d %d %d\n", in[ac.nd[8]], out[ac.nd[8]], ac.nd[8]);
    return 0;
}
