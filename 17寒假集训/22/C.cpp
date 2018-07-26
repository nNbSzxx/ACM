#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 110;
const int INF = 9999;
struct T{
	int to,nt;
};
T t[MAX];
int n,m,cnt,head[MAX],degree[MAX];

void add(int u, int v)
{
	t[cnt].to = v;
	degree[v] ++;
	t[cnt].nt = head[u];
	head[u] = cnt;
	cnt ++;
}

int tsort(void)
{
	int visit[MAX];
	int dis[MAX];
	int cnt[MAX];
	queue<int> q;
//	memset(cnt,0,sizeof(cnt));

//	memset(visit,0,sizeof(visit));
//	for (int i = 0; i <= n; i ++) {
//		dis[i] = INF;
//	}
//	visit[1] = 1;
//	cnt[1] ++;
	int in = 0;
	int oncein = 0;
	for (int i = 0; i < n; i ++) {
		if (degree[i] == 0) {
			in ++;
			q.push(i);
		}
	}
	while (!q.empty() ) {
		int now = q.front(); q.pop();
		for (int i = head[now]; i; i = t[i].nt) {
			if (-- degree[t[i].to] == 0) {
				q.push(t[i].to);
				in ++;
			} 
		}
		
	}
	if (in < n) return 0;
	else return 1;
	
}

int main()
{
	while (~scanf("%d%d",&n,&m), n) {
		cnt = 1;
		memset(t,0,sizeof(t));
		memset(head,0,sizeof(head));
		memset(degree,0,sizeof(degree));
		for (int i = 0; i < m; i ++) {
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		if (tsort()) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
}
