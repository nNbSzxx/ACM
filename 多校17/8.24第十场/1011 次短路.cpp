#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLLI;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 100010;
struct edge {
	int v, w, nt;
} e[MAX * 2];
int n, m, cnt, head[MAX];
LL dis1[MAX], dis2[MAX];
void add(int u, int v, int w)
{
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].nt = head[u];
	head[u] = cnt ++;
	return ;
}
void init()
{
	cnt = 1;
	memset(head, 0, sizeof head);
	memset(dis1, 0x3f, sizeof dis1);
	memset(dis2, 0x3f, sizeof dis2);
}
void solve()
{
	priority_queue<PLLI, vector<PLLI>, greater<PLLI>> q;
	dis1[1] = 0;
	q.push(PLLI(0, 1));
	while (!q.empty()) {
		PLLI p = q.top(); q.pop();
		int u = p.second;
		LL d = p.first;
		for (int i = head[u]; i; i = e[i].nt) {
			LL d2 = d + e[i].w;
			int v = e[i].v;
			if (d2 < dis1[v]) {
				swap(d2, dis1[v]);
				q.push(PLLI(dis1[v], v));
			}
			if (d2 < dis2[v] && d2 > dis1[v]) {
				dis2[v] = d2;
				q.push(PLLI(dis2[v], v));
			}
		} 
	}
	printf("%lld\n", dis2[n]);
}
int main()
{
	pair<int, int> p1(1, 5), p2(2, 4);
	//cout << (p1 > p2) << endl;
	int t;
	scanf("%d", &t);
	while (t --) {
		init();
		scanf("%d%d", &n, &m);
		int u, v, w;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		solve();
	}
}
