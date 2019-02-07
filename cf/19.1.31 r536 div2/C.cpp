#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int MAX = 3e5 + 10;

int main()
{
	int n;
	scanf("%d", &n);
	int a[MAX];
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for (int i = 1; i <= n / 2; i ++) {
		//cout << a[i] << " " << (a[n - i + 1]) << endl;
		ans += 1LL * (a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]);
	}
	printf("%lld\n", ans);
	return 0;
}
