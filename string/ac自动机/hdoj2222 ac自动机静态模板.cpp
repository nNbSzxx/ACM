#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int n, ans;

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
int acm::tot = MAX;
int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		ans = 0;
		char s[MAX];
		ac.init();
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf(" %s", s);
			ac.add(s, strlen(s));
		}
		ac.makefail();
		scanf(" %s", s);
		ac.match(s, strlen(s));
		printf("%d\n", ans);
	}
	return 0;
} 
