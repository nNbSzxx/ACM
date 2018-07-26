#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n,m,t;
	int num[100005];
	int sum[100005];
	int visit[5010];
	scanf("%d",&t);
	while (t --) {
		memset(visit,0,sizeof(visit));
		scanf("%d%d",&n,&m);
		int flag = 0;
		sum [0] = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&num[i]);
			if (!flag) {
				sum[i] = sum[i-1] + num[i];
				if (sum[i] % m == 0) flag = 1;
				visit[sum[i] % m] ++;
			
				if (visit[sum[i] % m] > 1) {
					flag = 1;
				}
			}
		}
		if (flag) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
		
	return 0;
}
