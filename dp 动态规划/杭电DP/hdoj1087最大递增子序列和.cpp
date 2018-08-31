#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1006;
int main()
{
	long long sum[MAX];
	long long a[MAX];
	int n;
	while (~scanf("%d", &n), n) {
		for (int i = 1; i <= n ; i  ++) {
			scanf("%lld",&a[i]);
		}
		
		for (int i = 1; i <= n ; i ++) {
			sum[i] = a[i];
			for (int j = 1; j < i ; j ++) {
				if (a[i] > a[j] && sum[j] + a[i] > sum[i]) {
					sum[i] = sum[j] + a[i];
				}
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (ans< sum[i]) {
				ans = sum[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
