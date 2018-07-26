#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

unsigned long long gcd(long long n, long long m)
{
	long long r;
	while (m) {
		r = n % m;
		n = m;
		m = r;
	}
	return n;
}

int main()
{
	int t;
	unsigned long long n,m;
	scanf("%d",&t);
	while (t --) {
		//printf("%d\n",gcd(12,18));
		scanf("%llu%llu",&n,&m);
		if (n == m) {
			puts("0");
			continue;
		}
		if (n == 0) {
			puts("-1");
			continue;
		}
		if (n > m || m % n ) {
			puts("-1");
			continue;
		}
		int cnt = 0;
		int flag = 0;
		while (n != m) {
			long long g = gcd(n, m / n);
			if (g == 1) {
				flag = 1;
				break;
			} else {
				n *= g;
				cnt ++;
			}
		}
		if (flag) {
			puts("-1");
			continue;
		} else {
			printf("%d\n",cnt);
		}
	}
	
	return 0;
}
