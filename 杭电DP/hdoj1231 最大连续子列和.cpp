#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	int a[10010];
	while (~scanf("%d",&n), n) {
		
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
		}
		a[n + 1] = -0x3f3f3f3f;
		int max = 0, ans = -1;
		int abegin = a[1], aend = a[1];
		int begin = a[1], end = a[1]; 
	
		for (int i = 1; i <= n; i ++) {
			max += a[i];
			end = a[i];
			if (max < 0) {
				max = 0;
				begin = a[i + 1];
				end = a[i + 1];
			} else
			if (max > ans) {
				abegin = begin;
				aend = end;
				ans = max;
			}
		}
		if (ans == -1) printf("%d %d %d\n",0,a[1],a[n]);
		else printf("%d %d %d\n",ans, abegin ,aend);
	}
	return 0;
}
