#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n, m; 
vector<int> s[MAX];
vector<int> e[MAX], ans;
int vis[MAX];

inline void label(int x, int k)
{
	if (!vis[x]) vis[x] = k;
	if (vis[x] != k) {
		puts("No");
		exit(0);
	}
}

void dfs(int x)
{
	ans.push_back(x);
	for (int i = 0; i < e[x].size(); i ++) {
		if (vis[e[x][i]] == -1) {
			puts("No");
			exit(0);
		}
		if (!vis[e[x][i]]) {
			vis[e[x][i]] = 2;
			dfs(e[x][i]);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	int t, l;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &l);
		for (int j = 0; j < l; j ++) {
			scanf("%d", &t);
			s[i].push_back(t);
		}
	}
	for (int i = 1; i < n; i ++) {
		int len = min(s[i].size(), s[i + 1].size());
		int flag = 0;
		for (int j = 0; j < len; j ++) {
			if (s[i][j] != s[i + 1][j]) {
				flag = 1;
				if (s[i][j] < s[i + 1][j]) {
					e[s[i + 1][j]].push_back(s[i][j]);
				} else {
					label(s[i + 1][j], -1); //vis[s[i + 1][j]] = 1;
					label(s[i][j], 1); //vis[s[i][j]] = -1;
				}
				break;
			}
		}
		if (!flag && s[i].size() > s[i + 1].size()) {
			puts("No");
			return 0;
		}
	}
	for (int i = 1; i <= m; i ++) {
		if (vis[i] == 1) {
			dfs(i);
		}
	}
	puts("Yes");
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i ++) {
		printf("%d ", ans[i]);
	}
	return 0;
}



