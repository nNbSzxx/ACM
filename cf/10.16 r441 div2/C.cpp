#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int cnt = 0;
	vector<int> ans;
	for (int i = max(0, n - 100); i <= n; i ++) {
		int t = i, sum = i;
		while (t) {
			sum += t % 10;
			t /= 10;
		}
		if (sum == n) {
			ans.push_back(i);
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i ++) {
		printf("%d ", ans[i]);
	}
}
