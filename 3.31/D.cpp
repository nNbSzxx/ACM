#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int prime[1000000];
int cnt = 0;
bool isprime[10000005];

long long solve(long long x)
{
	int fac = 0;
	long long ans = 1;
	while (prime[fac] * prime[fac] <= x && fac < cnt) {
		int now = 0;
		while (x % prime[fac] == 0) {
			x /= prime[fac];
			now ++;
		}
		fac ++;
		ans *= (2*now+1);
	}
	if (x > 1) ans *= 3;
	return ans / 2 + 1;
}

int main()
{
	memset(isprime,1,sizeof(isprime));
	for (int i = 2; i <= 1e7; i ++) {
		if (isprime[i]) {
			prime[cnt ++] = i;
			for (int j = i; j <= 1e7; j += i) {
				isprime[j] = 0;
			}
		}
	}
	int t,tc = 0;
	scanf("%d",&t);
	while (t--) {
		long long n;
		scanf("%lld",&n);
		printf("Case %d: %lld\n",++tc,solve(n));
	}
	return 0;
}
