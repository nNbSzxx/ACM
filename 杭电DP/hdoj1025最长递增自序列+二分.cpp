#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;
const int MAX = 500005;
struct Road {
	int u,v;
};
Road r[MAX];
int dp[MAX], len;
bool cmp(Road &m1, Road &m2)
{
	if (m1.u < m2.u) return true;
	return false;
}
int bins(int key)
{
	int left = 1, right = len;
	int mid;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (dp[mid] == key) return mid;
		if (dp[mid] > key) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return left;
}
int main()
{	
	int n;	
	int tc = 1;
	while (~scanf("%d",&n)) {
		for (int i = 1; i <= n; i ++)
			scanf("%d%d",&r[i].u,&r[i].v);
		sort(r+1,r+n+1,cmp);	
		memset(dp,0,sizeof(dp));
		int t;
		dp[1] = r[1].v; 
		len = 1;
		for (int i = 2; i <= n; i ++) {
			int t = bins(r[i].v);
			dp[t] = r[i].v;
			if (t > len) len ++;
		}
		
	//	for (int i = 1; i <= cnt; i ++) {
	//		printf("%d ",dp[i]);
	//	}
	//	printf("\n");
		printf("Case %d:\n",tc ++);
		if (len == 1)
			printf("My king, at most %d road can be built.\n\n",len);		
		else
			printf("My king, at most %d roads can be built.\n\n",len);
	}
	return 0;
}
