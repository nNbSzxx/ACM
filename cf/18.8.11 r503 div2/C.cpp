#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 3010;
const long long INF = 3e12 + 10;
int n, m;
int cnt[MAX];
int p[MAX], c[MAX], sor[MAX];
vector<int> par[MAX];

long long cal(int cnt)
{
	long long ans = 0;
	int remain = cnt - par[1].size();
	int cur = 0;
	for (int i = 2; i <= m; i ++) {
		int id = 0;
		if (par[i].size() >= cnt) {
			id = par[i].size() - cnt + 1;
		}
		remain -= id;
		if (remain < 0) {
			return INF;
		}
		for (int j = 0; j < id; j ++) {
			ans += par[i][j];
		}
		for (int j = id; j < par[i].size(); ++ j) {
			sor[cur ++] = par[i][j];
		}
	}
//	cout << ans << endl;
	if (remain > 0)
		sort(sor, sor + cur);
	for (int i = 0; i < remain; i ++) {
		ans += sor[i];
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &p[i], &c[i]);
		par[p[i]].push_back(c[i]);
	}
	for (int i = 1; i <= m; i ++) {
		sort(par[i].begin(), par[i].end());
	}
	long long ans = INF;
	for (int i = par[1].size(); i <= n; i ++) {
//		cout << cal(i) << endl;
		ans = min(ans, cal(i));
	}
	cout << ans << endl;
	return 0;
}
