#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int t, num[10005],n;
	scanf("%d",&t);
	while (t --) {
		scanf("%d",&n);
		for (int i = 0; i < n; i ++) {
			scanf("%d",&num[i]);
		}
		sort(num,num+n);
		int ans,loc = 0;
		for (int i = 1; i < n; i ++) {
			if (num[i] != num[i-1] + 1) {
				loc = i;
				break;
			}
		}
		if (loc == n - 1) {
			ans = num[n-1];
		} else {
			if (num[loc] + 1 != num[loc + 1]) {
				ans = num[loc];
			} else {
				ans = num[loc-1];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
