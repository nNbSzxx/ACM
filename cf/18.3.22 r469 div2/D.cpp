#include <bits/stdc++.h>
using namespace std;
long long n, q;

long long dfs(long long x)
{
	while ((x & 1) == 0) {
		x = x / 2 + n;
	}
	return (x + 1) >> 1;
}
int main()
{
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= q; i ++) {
		long long t;
		scanf("%lld", &t);
		printf("%lld\n", dfs(t));
	}
	return 0;
}
