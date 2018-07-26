#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 10;
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
	int n;
	scanf("%d", &n);
	int t;
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &t);
		if (q.empty() || q.top() >= t) {
			q.push(t);
		} else {
			ans += t - q.top();
			q.pop();
			q.push(t); q.push(t);
		}
	}
	printf("%lld\n", ans);
}
