#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;



int main()
{
	int n,a,b;
	while (~scanf("%d%d%d",&n,&a,&b)) {
		unsigned long long ans = 1, ca = 1, cb = 1,temp = 1;
		for (int i = 1; i <= a || i <= b; i ++) {
			temp = temp * (n + i - 1) / i;
			ca += temp;
			cb += temp;
			if (i == a) {
				ans *= ca;
			}
			if (i == b) {
				ans *= cb;
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}
