// 要用java大数 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long p(long long base , long long r)
{
	long long ret = 1;
	while (r) {
		if (r & 1) {
			ret *= base;
		}
		r >>= 1;
		base *= base;
	}   
	return ret;        		
} 
int main()
{
	int n, c;
	while (~scanf("%d%d", &n, &c)) {
		long long ans;
		if (n & 1) {
			ans = (4 * p(c, n * (n - 1) / 2 + n));
		} else {
			ans = (2 * p(c, n / 2 * n) + 2 * p(c, n * (n - 1) / 2 + n));	
		}
		ans += p(c, n * n) + 2 * p(c, n * n / 4 + (n & 1)) + p(c, n / 2 * n + (n & 1));
		ans /= 8;
		printf("%lld\n", ans);
	}     
}
