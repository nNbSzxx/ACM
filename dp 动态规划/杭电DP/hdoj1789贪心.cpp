//while(true) RP++;
#include<cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct Work{
	int score;
	int dead;
};
bool cmp(Work &w1, Work &w2)
{
	return w1.score > w2.score;
}

int main()
{
	int t;
	scanf("%d",&t);
	Work w[1010];
	int visit[1010];
	while (t --) {
		int n;
		scanf("%d",&n);
		memset(visit,0,sizeof(visit));
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&w[i].dead);
		}
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&w[i].score);
		}
		sort(w+1,w+1+n,cmp);
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			int flag = 0;
			for (int j = w[i].dead; j >= 1; j --) {
				if (!visit[j]) {
					visit[j] = 1;
					flag = 1;
					break;
				}
			}
			if (!flag) {
				ans += w[i].score;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

