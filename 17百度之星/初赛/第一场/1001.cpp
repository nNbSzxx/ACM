#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int ans;

void solve(int x)
{
	int i = 2, times;
	while (i * i <= x) {
		times = 1;
		while (x % i == 0) {
			x /= i;
			times ++;
		}
		ans *= times;
		i ++;
	}
	if (x != 1)
		ans *= 2;
}

int main()
{
	int t, d;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &d);
		ans = 1;
		solve(d - 1);
		printf("%d\n", ans);
	}
	return 0;
}
