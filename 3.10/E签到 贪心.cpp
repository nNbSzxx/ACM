#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;

int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		int n,m,p,q;
		scanf("%d%d%d%d",&n,&m,&p,&q);
		double aver = 1.0 * q / m; 
		int ans = 0;
		if (aver < p) {
			
			ans = n / m * q;
			n %= m;
			if (n) {
				if (q < n * p) ans += q;
				else ans += p * n;
			}
		} else {
			ans = n * p;
		}
		printf("%d\n",ans);
	}
	return 0;
}
