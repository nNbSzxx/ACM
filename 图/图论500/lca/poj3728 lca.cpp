#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 5e4 + 10;
const int MAXH = 18;
struct edge {
	int v, nt;
} e[MAX << 1];
int head[MAX], w[MAX], cnte;
// anc[i][j]��ʾi�Žڵ�������2^j���ڵ�ı�ţ��������� 
int anc[MAX][MAXH], dep[MAX];
int n, qy, root;
int curmax, curmin;
queue<int> q;

void init()
{
	cnte = 0;
	memset(head, 0, sizeof head);
}

void add(int u, int v)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

// ���������������anc�� 
void bfs(int root)
{
	dep[root] = 1;
	q.push(root);
	for (int i = 0; i < MAXH; i ++) {
		anc[root][i] = root;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u != root) {
			for (int i = 1; i < MAXH; i ++) {
				anc[u][i] = anc[anc[u][i - 1]][i - 1];
			}
		}
		for (int i = head[u]; i; i = e[i].nt) {
			int v = e[i].v;
			if (v != anc[u][0]) {
				dep[v] = dep[u] + 1;
				anc[v][0] = u;
				q.push(v);
			}
		}
	}
}

// ��x�ڵ������ƶ�h�㣬�����ƶ���ڵ�ı�� 
int swim(int x, int h)
{
	int ret = x;
	// �Ӷ����ƽǶȿ�����6=110����ô����2�㣬����4�� 
	for (int i = 0; h; i ++, h >>= 1) {
		if (h & 1) {
			ret = anc[ret][i];
		}
	}
	return ret;
}

int lca(int x, int y)
{
	if (dep[x] < dep[y]) {
		swap(x, y);
	}
	// �Ȱ��������Ƶ�ͬһ�߶� 
	x = swim(x, dep[x] - dep[y]);
	if (x == y) {
		return x;
	}
	// ��һ�����ĸ߶�һ����ǰһ�����ĸ߶Ȼ�С
	// �����÷�֤��֤�� 
	for (int i = MAXH - 1; i >= 0; i --) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0]; 
}

int upscanv(int v, int lc)
{
	int ret = 0;
	while (true) {
		ret = max(ret, curmax - v);
		curmax = max(curmax, w[v]);
		if (v == lc) break;
		v = anc[v][0];
	}
	return ret;
}

int upscanu(int u, int lc)
{
	int ret = 0;
	while (true) {
//		printf("in u scan: %d curmin: %d\n", u, curmin);
		ret = max(ret, u - curmin);
		curmin = min(curmin, w[u]);
		if (u == lc) break;
		u = anc[u][0];
	}
	return ret;
}

int main()
{
	while (~scanf("%d", &n)) {
		init();
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &w[i]);
		}
		int u, v;
		for (int i = 1; i < n; i ++) {
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		bfs(1);
		scanf("%d", &qy);
		while (qy --) {
			scanf("%d%d", &u, &v);
			int lc = lca(u, v);
			//printf("%d\n", lc);
			curmax = -MAX; curmin = MAX;
			int maxans = upscanu(u, lc);
			int t1 = upscanv(v, lc);
			int t2 = curmax - curmin;
			//printf("%d ", maxans);
			maxans = max(maxans, t1);
			maxans = max(maxans, t2);
			//printf("%d %d %d\n", t1, t2, maxans);
			printf("%d\n", maxans);
		}
	}
	return 0;
}



