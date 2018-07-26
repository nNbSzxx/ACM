#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
const int MAX = 100005;
const int INF = 0x3f3f3f3f;
int main()
{
	int t;
	int num[MAX];
	scanf("%d",&t);
	while (t --) {
		int n;
		int max ;
		scanf("%d",&n);
		int ans = -INF;
		int temp;
		scanf("%d",&max);
		for (int i = 1 ; i < n ; i ++) {
			scanf("%d",&temp);
			if (max - temp > ans) {
				ans = max - temp;
			}
			if (max < temp) {
				max = temp;
			}
		}
		printf("%d\n",ans);
		
	}
}
