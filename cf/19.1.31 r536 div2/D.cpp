#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int MAX = 3e5 + 10;

struct edge {
	int u, v, nt;
} e[MAX];
int head[MAX], cnte, vis[MAX];

void add(int u, int v)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

int main()
{
	memset(head, 0, sizeof head);
	memset(vis, 0, sizeof vis);
	cnte = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	
	vector<int> ans;
	int find = 0;
	priority_queue<int> q;
	q.push(-1);
	vis[1] = 1;
	while (find < n) {
		int u = -q.top();
		q.pop();
		// vis[u] = 1;
		ans.push_back(u);
		++ find;
		if (find == n) {
			break;
		}
		for (int i = head[u]; i; i = e[i].nt) {
			if (!vis[e[i].v]) {
				q.push(- e[i].v);
				vis[e[i].v] = 1;
			}
		}
	}
	for (auto i : ans) {
		printf("%d ", i);
	}
	puts("");
	return 0;
}
