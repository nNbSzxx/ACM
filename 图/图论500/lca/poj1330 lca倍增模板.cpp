// ������LCA 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1e4 + 10;
// �����ȶԶ�ȡ���� 
const int MAXH = 16;
queue<int> q;
struct edge {
	int v, nt;
} e[MAX];
int n, isroot[MAX], head[MAX], cnte, dep[MAX];
// anc[i][j]��ʾ��i���ڵ�������2^j���Ľڵ�
// anc[i][0]���Ǹ��׽ڵ�
// �����2^j��󳬹���root����ôanc[i][j] = root
int anc[MAX][MAXH]; 

void init()
{
	cnte = 0;
	memset(head, 0, sizeof head);
	memset(isroot, -1, sizeof isroot);
}

void add(int u, int v)
{
	++ cnte;
	e[cnte].v = v;
	e[cnte].nt = head[u];
	head[u] = cnte;
}

// x������h���Ľڵ��� 
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
		for (int i = head[u]; i; i = e[i].nt) {
			int v = e[i].v;
			if (v != anc[u][0]) {
				dep[v] = dep[u] + 1;
				anc[v][0] = u;
				for (int i = 1; i < MAXH; i ++) {
					// ���� 
					anc[v][i] = anc[anc[v][i - 1]][i - 1];
				}
				q.push(v);
			}
		}
	}
}

int lca(int x, int y)
{
	if (dep[x] < dep[y]) {
		swap(x, y);
	}
	// �Ȱѽ����������ǳ��ͬһ�߶� 
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
	// ѭ��������anc[x][0] = anc[y][0] = lca 
	return anc[x][0];
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		init();
		scanf("%d", &n);
		int u, v;
		for (int i = 1; i < n; i ++) {
			scanf("%d%d", &u, &v);
			add(u, v);
			isroot[v] = 0;
		}
		int root = -1;
		for (int i = 1; i <= n; i ++) {
			if (isroot[i]) {
				root = i;
				break;
			}
		}
		bfs(root);
		scanf("%d%d", &u, &v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}




