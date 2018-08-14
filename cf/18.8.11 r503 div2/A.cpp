#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, h, a, b, k;

int main()
{
	scanf("%d%d%d%d%d", &n, &h, &a, &b, &k);
	while (k --) {
		int t1, f1, t2, f2;
		scanf("%d%d%d%d", &t1, &f1, &t2, &f2);
		int ans = 0;
		ans += abs(t1 - t2);
		if (t1 == t2) {
			ans += abs(f1 - f2);
		} else if (f1 <= b && f1 >= a) {
			ans += abs(f1 - f2);
		} else if (f1 < a) {
			ans += (a - f1 + abs(a - f2));
		} else if (f1 > b) {
			ans += (f1 - b + abs(b - f2));
		}
		printf("%d\n", ans);
	}
	return 0;
}
