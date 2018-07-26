#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t;
	unsigned long long n;
	scanf("%d",&t);
	while (t --) {
		scanf("%llu",&n);
		unsigned long long ans;
		if (n < 4) {
			printf("%d\n",n);
			continue;
		}
		ans = n * (n - 1) /2 * (n - 2) /3 * (n - 3) / 4 + n;
		printf("%llu\n",ans);
	}
	return 0;
}
