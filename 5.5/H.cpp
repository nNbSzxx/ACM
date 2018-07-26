#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n,k;
	int cnt[110],a[110];
	while (~scanf("%d%d",&n,&k)) {
		int aver = n / k;
		memset(cnt,0,sizeof(cnt));
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
			cnt[a[i]] ++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (cnt[i] > aver) {
				ans = ans + cnt[i] - aver;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
