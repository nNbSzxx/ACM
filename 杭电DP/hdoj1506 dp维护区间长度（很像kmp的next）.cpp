#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100005;
int main()
{
	int n;
	long long h[MAX];
	long long l[MAX], r[MAX];
	while (~scanf("%d",&n), n) {
		for (int i = 1; i <= n; i ++) {
			scanf("%lld",&h[i]);
		}
		int t;
		l[1] = 1;
		r[n] = n;
		for (int i = 2; i <= n; i ++) {
			t = i;
			while (t > 1 && h[i] <= h[t - 1]) {
				t = l[t - 1];
			}
			l[i] = t ;
		}
		
		for (int i = n - 1; i >= 1; i--) {
			t = i ;
			while (t < n && h[i] <= h[t + 1]) {
				t = r[t + 1];
			}
			r[i] = t ;
		}
		
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			if ((r[i] - l[i] + 1) * h[i] > ans)
				ans = (r[i] - l[i] + 1) * h[i];
		}
		printf("%lld\n",ans);
	}
} 
