#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int n;
int cnt[10010];
vector<int> num;

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		num.clear();
		int ans = -1;
		for (int i = 1; i <= n; i ++) {
			int a;
			scanf("%d", &a);
			++ cnt[a];
			if (cnt[a] == 2) {
				num.push_back(a);
			}
			if (cnt[a] == 4) {
				ans = a;
			}
		}
		if (ans != -1) {
			printf("%d %d %d %d\n", ans, ans, ans, ans);
			continue;
		}
		sort(num.begin(), num.end());
		double minn = 33333333;
		int ans1 = -1, ans2 = -1;
		for (int i = 1; i < num.size(); i ++) {
			if (1.0 * num[i] / num[i - 1] < minn) {
				minn = 1.0 * num[i] / num[i - 1];
				ans1 = num[i - 1];
				ans2 = num[i];
			}
		}
		printf("%d %d %d %d\n", ans1, ans1, ans2, ans2);
	}
	return 0;
}
