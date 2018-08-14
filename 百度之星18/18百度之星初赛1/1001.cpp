#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX = 1e3 + 10;
int n;
int a[MAX];

int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + 1 + n);
		int ans = -1;
		for (int i = n; i >= 3; i --) {
			for (int j = i - 1; j > 1; j --) {
				if (a[j] + a[j - 1] > a[i]) {
					ans = max(ans, a[i] + a[j - 1] + a[j]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
