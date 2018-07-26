#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>
using namespace std;

int main()
{
	int t;
	long long n;
	scanf("%d",&t);
	int tc = 0;
	while (t --) {
		scanf("%lld",&n);
		long long ans = n - (long long)sqrt(n) - (long long)sqrt(n/2) ;
		printf("Case %d: %lld\n",++tc,ans);
	}
}
