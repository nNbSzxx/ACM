#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const long long MOD = 1e9 + 7;
pair<int, int> vid[MAX];
stack<pair<int, int> > s;
int l[MAX], r[MAX];
int n;
long long ans = 1;
long long inv[MAX];

void init()
{
	inv[1] = 1;
	for(long long i = 2; i < MAX; i++)
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
}

int build()
{
	s.push(vid[1]);
	int id = -vid[1].second;
	l[id] = r[id] = 0;
	for (int i = 2; i <= n; i ++) {
		pair<int, int> now;
		pair<int, int> last = make_pair(0, 0);
		while (!s.empty()) {
			now = s.top();
			if (now > vid[i]) {
				break;
			}
			last = s.top();
			s.pop();
		}
		if (s.empty()) {
			int curid = -vid[i].second;
			int lid = -last.second;
			l[curid] = lid;
			r[curid] = 0;
		} else {
			int curid = -vid[i].second;
			int lid = -last.second;
			int nid = -now.second;
			l[curid] = lid;
			r[curid] = 0;
			r[nid] = curid;
		}
		s.push(vid[i]);
	}

	pair<int, int> root;
	while (!s.empty()) {
		root = s.top();
		s.pop();
	}
	return -root.second;
}

int dfs(int x)
{
	int cnt = 1;
	if (l[x] != 0) {
		cnt += dfs(l[x]);
	}
	if (r[x] != 0) {
		cnt += dfs(r[x]);
	}
	ans = (ans * inv[cnt]) % MOD;
	return cnt;
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &vid[i].first);
			
			vid[i].second = -i;
		}
		int root = build();
		ans = 1;
		dfs(root);
		ans = ans * n % MOD * inv[2] % MOD;
		printf("%lld\n", ans);
	} 
	return 0;
}
