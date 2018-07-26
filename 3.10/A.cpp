#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 305;
int map[MAX][MAX];
long long dis[MAX];
bool visit[MAX];
int n,m;

long long spfa (int start)
{
	memset(visit,0,sizeof(visit));
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	memset(dis,0x3F,sizeof(dis));
	dis[start] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop(); 
		for (int i = 1;i <= n; i ++) {
			if (map[now][i] != INF)	
				if (dis[i] > dis[now] + map[now][i]) {
					dis[i] = dis[now] + map[now][i];
					if (!visit[i]) {
						q.push(i);
						visit[i] = 1;
					}
				}
		}
		visit[now] = 0;
	}
	long long cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cnt += dis[i];
	}

	return cnt;
}

int main()
{
	while (~scanf("%d%d",&n,&m)) {
		memset(map,0x3f,sizeof(map));
//		for (int i = 1; i <= n; i ++) {
//			map[i][i] = 0;
//		}
		int a[MAX];
		int cnt[MAX],maxid = 1;
		memset(cnt,0,sizeof(cnt));
		for (int i = 1; i <= m; i ++) {
			int t;
			scanf("%d",&t);
			for (int j = 1; j <= t; j ++) {
				scanf("%d",&a[j]);
				if ( ++ cnt[a[j]] > cnt[maxid]) {
					maxid = a[j];
				}
				
				for (int k = 1; k < j; k ++) {
					map[a[j]][a[k] ]= 1;
					map[a[k]][a[j] ]= 1;
				}
			}
		}
		
		
	
		long long ans = spfa(maxid);
		double dans = 1.0 * ans * 100 / (n - 1);
		printf("%.0lf\n",dans);
	}
	return 0;
}
