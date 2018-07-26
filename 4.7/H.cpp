#include <cstdio>
#include <cstring>
using namespace std;
	int n,t,maxn,maxid,cnt[1000005];
int main()
{

	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n);
	scanf("%d",&t);
	maxid = t;
	cnt[t] ++;
	for (int i = 1; i < n ; i++) {
		scanf("%d",&t);
		cnt[t] ++;
		if (cnt[t] > cnt[maxid]) maxid = t;
	}
	printf("%d\n",maxid);
	return 0;
 } 
