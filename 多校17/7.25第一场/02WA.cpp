#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 10;
const long long mod = 1e9 + 7;
int loc[26], cnt[26][MAX], vis[26], m[26];
int n;
char s[MAX];

bool cmp(const int& l, const int& r)
{
	if (m[l] < m[r]) return true;
	if (m[l] > m[r]) return false;
	for (int i = m[l]; i >= 0; i --) {
		if (cnt[l][i] < cnt[r][i]) {
			return true;
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
			scanf("%s", s);
			len = strlen(s);
			if (len != 1) {
				vis[s[0] - 'a'] = 1;
			}
			for (int i = 0; i < len; i ++) {
				cnt[s[i] - 'a'][len - i - 1] ++;
				m[s[i] - 'a'] = max(m[s[i] - 'a'], len - i - 1);
			}
		}
		for (int i = 0; i < 26; i ++) {
			for (int j = 0; j <= m[i]; j ++) {
				if (cnt[i][j] > 25) {
					cnt[i][j + 1] += cnt[i][j] / 26;
					cnt[i][j] %= 26;
					if (j == m[i]) ++ m[i];
				}
			}
		}
		for (int i = 0; i < 26; i ++) {
			loc[i] = i;
		}
		sort(loc, loc + 26, cmp);
		for (int i = 0; i < 26; i ++) {
			if (!vis[loc[i]]) {
				for (int j = i; j >= 1; j --) {
					loc[j] = loc[j - 1];
				}
				break;
			}
		}
		/*
		for (int i = 0; i < 26; i ++) {
			cout << i << " " << loc[i] << endl;
		}
		cout << "vis: " << endl;
		for (int i = 0; i < 26; i ++) {
			cout << i << " " << vis[i] << endl;
		}
		cout << "m: " << endl;
		for (int i = 0; i < 26; i ++) {
			cout << i << " " << m[i] << endl;
		}
		*/	
		long long ans = 0;
		long long j, k;
		for (int i = 1; i < 26; i ++) {
			for (j = 0, k = 1; j <= m[loc[i]]; j ++, k = (k * 26) % mod) {
				ans = (ans + (long long)i * cnt[loc[i]][j] * k) % mod;
			}
		}
		printf("Case #%d: ", t ++);
		printf("%lld\n", ans);
	}
	
	return 0;
}
