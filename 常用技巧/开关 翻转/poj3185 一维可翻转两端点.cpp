#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 25;
const int INF = 0x3f3f3f3f;
int a[MAX];

int solve()
{
	int temp[MAX];
	int cnt = 0;
	memcpy(temp, a, sizeof a);
	for (int i = 2; i <= 20; i ++) {
		if (temp[i - 1] == 1) {
			++ cnt;
			temp[i - 1] ^= 1;
			temp[i] ^= 1;
			temp[i + 1] ^= 1;
		}
	}
	if (temp[20] == 1) {
		return INF;
	} else {
		return cnt;
	}
}

int main()
{
	while (~scanf("%d", &a[1])) {
		for (int i = 2; i <= 20; i ++) {
			scanf("%d", &a[i]);
		}
		int ans = solve();
		a[1] ^= 1;
		a[2] ^= 1;
		ans = min(ans, solve() + 1);
		printf("%d\n", ans);
	}
	return 0;
}
