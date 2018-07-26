#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1e5 + 10;
struct cow {
	int cost;
	int score;
} c[MAX];
int n, m, f;
long long cost1[MAX], cost2[MAX];
priority_queue<int> q1, q2;

bool cmp(const cow& c1, const cow& c2)
{
	return (c1.score > c2.score || (c1.score == c2.score && c1.cost < c2.cost));
}

int main()
{
	while(~scanf("%d%d%d", &n, &m, &f)) {
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d", &c[i].score, &c[i].cost);
		}
		sort(c + 1, c + 1 + m, cmp);
		while (!q1.empty()) {
			q1.pop();
		}
		while (!q2.empty()) {
			q2.pop();
		}
		if (n == 1) {
			q1.push(-1);
			q2.push(-1);
		}
		long long costsum1 = 0, costsum2 = 0;
		for (int i = 1; i <= n / 2; i ++) {
			q1.push(c[i].cost);
			costsum1 += c[i].cost;
		}
		for (int i = n / 2 + 1; i <= m - n / 2; i ++) {
			cost1[i] = costsum1;
			if (q1.top() > c[i].cost) {
				costsum1 -= q1.top();
				costsum1 += c[i].cost;
				q1.pop();
				q1.push(c[i].cost);
			}
		}
		for (int i = m; i >= m - n / 2 + 1; i --) {
			q2.push(c[i].cost);
			costsum2 += c[i].cost;
		}
		for (int i = m - n / 2; i >= n / 2 + 1; i --) {
			cost2[i] = costsum2;
			if (q2.top() > c[i].cost) {
				costsum2 -= q2.top();
				costsum2 += c[i].cost;
				q2.pop();
				q2.push(c[i].cost);
			}
		}
//		for (int i = 1; i <= m; i ++) {
//			printf("%lld %lld\n", cost1[i], cost2[i]);
//		}
		long long ans = -1;
		for (int i = n / 2 + 1; i <= m - n / 2; i ++) {
			if (cost1[i] + cost2[i] + c[i].cost <= f) {
				ans = c[i].score;
				break;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
