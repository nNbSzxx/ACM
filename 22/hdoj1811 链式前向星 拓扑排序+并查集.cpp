#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;

const int MAXN = 10010;
const int MAXM = 20010;

struct E{
	int to;
	int w;
	int nt;
};
struct R{
	int x;
	int y;
	char c;
};

R read[MAXM];
E edge[MAXM];
int head[MAXN];
int uf[MAXN];
int cnt;
int cntn;
int degree[MAXN];
bool visit[MAXN];
int n,m;

int find(int x)
{
	while (x != uf[x]) {
		uf[x] = uf[uf[x]];
		x = uf[x];
	}
	return x;
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	uf[x] = y;
	return ;
}

void add(int u, int v, int val)
{
	edge[cnt].to = v;
	edge[cnt].nt = head[u];
	head[u] = cnt;
	cnt ++;
	degree[v] ++;
	return ;
}

int build(void) 
{
	for (int i = 0; i < m; i ++) {
		if (read[i].c == '=') continue;
		int x = find(read[i].x);
		int y = find(read[i].y);
		if (x == y) {
			return 0;
		}
		if (read[i].c == '>') add(x,y,1);
		if (read[i].c == '<') add(y,x,1);
	}
	return 1;
}

void tsort(void)
{
	queue<int> q;
	int in = 0;
	int oncein = 0;
	int flag = 0;
	
	for (int i = 0; i < n; i ++) {
		int father = find(i);
	
		if (degree[father] == 0 && !visit[father]) {
			q.push(father);
			assert(1);
			visit[father] = true;
			oncein ++;
			in ++;
		}
	}

	if (oncein > 1) {
		flag = 1;
	}
	oncein = 0;
	while (!q.empty()) {
	
		int now = q.front(); q.pop();
		for (int i = head[now]; i; i = edge[i].nt) {
			if (-- degree[edge[i].to] == 0) {
				q.push(edge[i].to);
				oncein ++;
				in ++;
			} 
		}
		if (oncein > 1) {
			flag = 1;
		}
		oncein = 0;
	}

	if (in < cntn) {
		printf("CONFLICT\n");
		return ;
	}
	if (flag) {
		printf("UNCERTAIN\n");
		return ;
	}
	printf("OK\n");
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d",&n,&m)) {
		cnt = 1;
		cntn = n;
		memset(head,0,sizeof(head));
		memset(edge,0,sizeof(edge));
		memset(degree,0,sizeof(degree));
		memset(visit,0,sizeof(visit));
		for (int i = 0; i <= n; i ++) {
			uf[i] = i;
		}
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %c%d",&read[i].x,&read[i].c,&read[i].y);
			if (read[i].c == '=') {
				Union(read[i].x, read[i].y);
				cntn --;
			}
		}
		if (!build()) {
			printf("CONFLICT\n");
			continue;
		}
		tsort();
	}

	return 0;
} 
