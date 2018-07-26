#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int mod = 1e9 + 7;
const int MAX = 2e5 + 10;
int n, m[26], cnt[26][MAX], loc[26], vis[26];
char s[MAX];

bool cmp(const int& l, const int& r)
{
	if (m[l] != m[r]) {
		return m[l] < m[r];
	}
	for (int i = m[l]; i >= 0; i --) {
		if (cnt[l][i] != cnt[r][i]) {
			return cnt[l][i] < cnt[r][i]; 
		}
	}
	return false;
}

int main()
{
	int t = 1;
	while (~scanf("%d", &n)) {
		memset(m, -1, sizeof(m));
		memset(cnt, 0, sizeof(cnt));
		memset(vis, 0, sizeof(vis));
		int len;
		while (n --) {
			scanf(" %s", s);
			len = strlen(s);
			if (len != 1) {
				vis[s[0] - 'a'] = 1;
			}
			for (int i = 0; i < len; i ++) {
				int c = s[i] - 'a';
				cnt[c][len - i - 1] ++;
				m[c] = max(m[c], len - i - 1); 
			}
		}
		for (int i = 0; i < 26; i ++) {
			for (int j = 0; j <= m[i]; j ++) {
				if (cnt[i][j] > 25) {
					cnt[i][j + 1] += cnt[i][j] / 26;
					cnt[i][j] %= 26;
					if (j == m[i]) {
						++ m[i];
					}
				}
			}
		}
		for (int i = 0; i < 26; i ++) {
			loc[i] = i;
		}
		sort(loc, loc + 26, cmp);
		for (int i = 0; i < 26; i ++) {
			if (!vis[loc[i]]) {
				for (int j = i; j; j --) {
					loc[j] = loc[j - 1];
				}
				break;
			}
		}
		long long ans = 0;
		long long k;
		int j;
		for (int i = 1; i < 26; i ++) {
			for (j = 0, k = 1; j <= m[loc[i]]; j ++, k = k * 26 % mod) {
				ans = (ans + k * i * cnt[loc[i]][j]) % mod;
			}
		}
		printf("Case #%d: %lld\n", t ++, ans);
	}
	return 0;
}
