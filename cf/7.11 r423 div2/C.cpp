#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 10;
string s[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	
	string ss;
	int k, loc;
	int maxx = -1;
	for (int i = 1; i <= n; i ++) {
		cin >> ss;
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			cin >> loc;
			maxx = max(maxx, loc + (int)ss.size() - 1);
			if (s[loc].size() < ss.size()) {
				s[loc] = ss;
			}
		}
	}
//	for (int i = 1; i <= maxx; i ++) {
//		cout << s[i] << endl;
//	}
	int cur = 1;
	for (int i = 1; i <= maxx; ++ i) {
		if (s[i] != "") {
			for (int j = cur - i; j < s[i].size(); j ++) {
				cout << s[i][j];
//				cout << " " << i << " " << j << " " << cur << endl;
				++ cur;
			}
		} else {
			if (cur > i) continue;
			cout << 'a';
			++ cur;
		}
	}
	cout << endl;
	return 0;
}
