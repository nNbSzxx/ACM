#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;
//	long long c = b - a;
	long long ans = 1;
	for (long long i = a + 1; i <= b; i ++) {
		if (ans == 0) break;
		ans = (ans * i) % 10;
//		cout << ans << endl;
	}
	printf("%lld\n", ans);
	return 0;
}
