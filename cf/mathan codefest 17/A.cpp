#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
string s[MAX];
map<string, int> mp;

int main()
{
	int n;
	cin >> n;
	string t;
	for (int i = 1; i <= n; i ++) {
		cin >> t;
		if (mp[t]) puts("YES");
		else puts("NO");
		++ mp[t];
	}
	return 0;
}
