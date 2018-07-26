#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 2501;

struct T{
	int w;
	int to;
	int nt;
};
T t[MAX];
int head[60];
int visit[60];
int cnt,cntr;
double rating[MAX];
int flag,n,m;

void add(int u, int v, int w)
{
	t[cnt].to = v;
	t[cnt].w = w;
	t[cnt].nt = head[u];
	head[u] = cnt ++;
	return ;
}

int sumw ;
int sume ;

void dfs(int father, int x, int isstart)
{
	if (father == x && !isstart) {
		rating[cntr ++] = 1.0 * sumw / sume;
		flag = 1;
		return ;
	}

	for (int i = head[x]; i ; i = t[i].nt) {
		int v = t[i].to;
		visit[v] = 1;
		sumw += t[i].w;
		sume ++;
		dfs(father,v,0);
		sumw -= t[i].w;
		sume --;
	}
}

int main()
{
	int tn;
	scanf("%d",&tn);
	int tc = 1;
	while (tn --) {
		memset(t,0,sizeof(t));
		memset(head,0,sizeof(head));
		memset(visit,0,sizeof(visit));
		cnt = 1;
		cntr = 0;
		flag = 0;
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= m; i ++) {
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			if (x == y) {
				rating[cntr ++] = w;
				continue;
			}
			add(x,y,w);
		}
		for (int i = 1; i <= n; i ++) {
			if (!visit[i]) {
				sumw = 0;
				sume = 0;
				dfs(i, i, 1);
			}
		}
		printf("Case #%d: ",tc ++);
		if (!flag) {
			puts("No cycle found.");
			continue;
		}
		sort(rating,rating + cntr);
		printf("%.2f\n",rating[0]);
	}
}
