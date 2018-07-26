#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
	long long b,q;
	set<int> s;
	int m,n, num[10005];
	while (~scanf("%lld%lld%d%d",&b,&q,&m,&n)) {
		int t;
		s.clear();
		for (int i = 0; i < n; i ++) {
			scanf("%d",&t);
			s.insert(t);
		}
		if (b == 0) {
			if (s.count(0)) {
				printf("0\n");
			} else {
				printf("inf\n");
			}
			continue;
		}
		if (q == 0) {
			int ans = 0;
			if (!s.count(b) && abs(b) <= m) ans = 1;
			if (!s.count(0)) ans = -1;
			if (abs(b) > m) ans = 0;
			if (ans == 1 || ans == 0) {
				printf("%d\n",ans);
			} 
			if (ans == -1) {
				printf("inf\n");
			}
			continue;
		}
		if (q == 1) {
			if (s.count(b) || abs(b) > m) {
				printf("0\n");
			} else {
				printf("inf\n");
			}
			continue;
		}
		if (q == -1) {
			int ans = 0;
			if (!s.count(b)) ans = -1;
			if (!s.count(-b)) ans = -1;
			if (abs(b) > m) ans = 0;
			if (ans) {
				printf("inf\n");
			} else {
				printf("0\n");
			}
			continue;
		}
		int ans = 0;
		while (abs(b) <= m) {
			if (!s.count(b)) ans ++;
			b *= q;
		}
		printf("%d\n",ans);
	}
	return 0;
}
