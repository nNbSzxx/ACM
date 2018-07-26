#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	string s[110];
	int l1 = 110, r1 = 110, l2 = -1, r2 = -1;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j ++) {
			if (s[i][j] == 'B') {
				++ cnt;
				if (i < l1) {
					l1 = i;
				}
				if (i > l2) {
					l2 = i;
				}
				if (j < r1) {
					r1 = j;
				}
				if (j > r2) {
					r2 = j;
				}
			}
		}
	}
	if (cnt == 0) {
		cout << 1 << endl;
		return 0;
	}
	int l = l2 - l1 + 1;
	int r = r2 - r1 + 1;
	int a = max(l, r);
	if (a > min(n, m)) {
		cout << -1 << endl;
		return 0;
	}
	cout << a * a - cnt << endl;
	return 0;
}
