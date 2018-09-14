#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1e4 + 10;

int t[MAX], f[MAX];
int sumt[MAX], sumf[MAX];
int dp[MAX];
int n, s;

struct node {
	int x, y, id;
	node (int xx, int yy, int idd) : x(xx), y(yy), id(idd) {}
};
deque<node> q;

long long det(long long x1, long long y1, long long x2, long long y2)
{
	return x1 * y2 - x2 * y1;
}

int main()
{
	while (~scanf("%d%d", &n, &s)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d", &t[i], &f[i]);
		}
		sumt[n + 1] = 0;
		sumf[n + 1] = 0;
		for (int i = n; i >= 1; i --) {
			sumt[i] = sumt[i + 1] + t[i];
			sumf[i] = sumf[i + 1] + f[i];
		}
		while (!q.empty()) {
			q.pop_back();
		}
		dp[n + 1] = 0;
		q.push_back(node(dp[n + 1], 0, n + 1));
		for (int i = n; i >= 1; i --) {
			while (q.size() >= 2) {
				node head = q.front(); q.pop_front();
				node mid = q.front();
				if ((mid.y - head.y) <= (sumf[i] * (mid.x - head.x))) {
					continue;
				} else {
					q.push_front(head);
					break;
				}
			}
			int j = q.front().id;
			dp[i] = dp[j] + (s + sumt[i] - sumt[j]) * sumf[i];
			int iny = dp[i], inx = sumt[i];
			while (q.size() >= 2) {
				node mid = q.back(); q.pop_back();
				node head = q.back();
				if (det(inx - mid.x, iny - mid.y, head.x - mid.x, head.y - mid.y) <= 0) {
					continue;
				} else {
					q.push_back(mid);
					break;
				}
			}
			q.push_back(node(inx, iny, i));
		}
		printf("%d\n", dp[1]);
	}
	return 0;	
} 
