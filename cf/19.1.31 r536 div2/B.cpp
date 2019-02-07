#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int MAX = 1e5 + 10;
long long num[MAX], c[MAX];
priority_queue<pair<int, int>> q;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &num[i]);
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &c[i]);
		q.push(make_pair(-c[i], -i));
	}
	for (int i = 1; i <= m; i ++) {
		int o;
		long long p;
		scanf("%d%lld", &o, &p);
		if (p <= num[o]) {
			num[o] -= p;
			printf("%lld\n", 1LL * p * c[o]);
		} else {
			long long ans = num[o] * c[o];
			long long left = p - num[o];
			num[o] = 0;
			if (q.empty()) {
				puts("0");
				continue;
			}
			int id = -q.top().second;
			while (num[id] < left) {
				ans += 1LL * num[id] * c[id];
				left -= num[id];
				num[id] = 0;
				q.pop();
				if (q.empty()) {
					break;
				} else {
					id = -q.top().second;
				}
			}
			if (q.empty()) {
				puts("0");
			} else {
				ans += 1LL * left * c[id];
				num[id] -= left;
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
