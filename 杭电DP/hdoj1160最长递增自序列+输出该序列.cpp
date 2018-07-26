#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;

struct Mice {
	int id, w, s;
};
bool cmp(Mice &m1, Mice &m2)
{
	if (m1.w > m2.w) return true;
	if (m1.w == m2.w && m1.s > m2.s) return true;
	return false;
}
int main()
{
	Mice m[1010];
	int cnt; 
	for (cnt = 1; ~scanf("%d%d",&m[cnt].w,&m[cnt].s);m[cnt].id = cnt,cnt ++) ;
	cnt --;
	sort(m+1,m+cnt+1,cmp);
	int dp[1010], path[1010];
	memset(dp,0,sizeof(dp));
	memset(path,0,sizeof(path));
	int t;
	int max = 0;
	for (int i = 1; i <= cnt; i ++) {
		dp[i] = 1;
		path[m[i].id] = m[i].id;
		for (int j = 1; j < i; j ++) {
			if (m[i].s > m[j].s && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				path[m[i].id] = m[j].id;
			}
		}
		if (dp[i] > max) {
			max = dp[i];
			t = m[i].id;
		}
	}
//	for (int i = 1; i <= cnt; i ++) {
//		printf("%d %d\n",m[i].w,m[i].s);
//	}
//	for (int i = 1; i <= cnt; i ++) {
//		printf("%d ",dp[i]);
//	}
//	printf("\n");
	
	printf("%d\n%d\n",max,t);
	while (path[t] != t) {
		printf("%d\n",path[t]);
		t = path[t];
	}
	return 0;
}
