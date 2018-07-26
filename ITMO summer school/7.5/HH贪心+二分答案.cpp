#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 105;
int n, vis[10010];
struct inter {
	int l, r;
} a[MAX];

bool cmp(const inter& lhs, const inter& rhs)
{
	if (lhs.r < rhs.r) return true;
	if (lhs.r == rhs.r && lhs.l < rhs.l) return true;
	return false; 
}
bool check(int x)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i ++) {
		int sum = 0;
		for (int j = a[i].l; j < a[i].r; j ++) {
			if (!vis[j])
				vis[j] = 1, sum ++;
			if (sum >= x) {
				break;
			}
		}
		if (sum < x) return false;
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i].l >> a[i].r ;
	}
	sort(a, a + n, cmp);
	int ans = 0;
	int l = 0, r = 1e4 + 1, mid;
	while (l <= r) {
		mid = (l + r) >> 1;;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans * n << endl;
	return 0;
}
