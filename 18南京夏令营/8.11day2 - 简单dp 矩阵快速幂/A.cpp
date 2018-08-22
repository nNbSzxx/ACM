#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX = 1e6 + 10;
long long f[MAX];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	f[0] = f[1] = 1;
	f[0] %= m;
	f[1] %= m;
	for (int i = 2; i <= n; i ++) {
		f[i] = (f[i - 1] + f[i - 2]) % m;
	}
	printf("%lld\n", f[n]);
	return 0;
}
