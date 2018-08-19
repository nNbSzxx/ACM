#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	long long n, q;
	scanf("%lld%lld", &n, &q);
	while (q --) {
		long long x, y, ans = 0;
		scanf("%lld%lld", &x, &y);
		if (n % 2 == 0) {
			if ((x + y) % 2 == 0) {
				ans = (n / 2) * (x - 1);
				if (x & 1) {
					ans += ceil(1.0 * y / 2);
				} else {
					ans += floor(1.0 * y / 2);
				}
			} else {
				ans = (n * n / 2) + (n / 2) * (x - 1);
				if (x & 1) {
					ans += floor(1.0 * y / 2);
				} else {
					ans += ceil(1.0 * y / 2);
				}
			}
		} else {
			
			if ((x + y) % 2 == 0) {
				if (x & 1) {
					ans += (n / 2 * 2 + 1) * (x / 2);
					ans += ceil(1.0 * y / 2);
				} else {
					ans += (n / 2 * 2 + 1) * (x / 2 - 1);
					ans += (n / 2 + 1);
					ans += ceil(1.0 * y / 2); 
				}
			} else {
				ans = n * n / 2 + 1;
				if (x & 1) {
					ans += (n / 2 * 2 + 1) * (x / 2);
					ans += ceil(1.0 * y / 2);
				} else {
					ans += (n / 2 * 2 + 1) * (x / 2 - 1);
					ans += (n / 2);
					ans += ceil(1.0 * y / 2); 
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
