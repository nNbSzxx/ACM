#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

map<string, int> cnt;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	for (int i = 0; i < n - 1; i ++) {
		cnt[string("") + s[i] + s[i + 1]] ++;
	}
	
	int maxx = 0;
	string ans = "";
	
	for (auto it = cnt.begin(); it != cnt.end(); ++ it) {
		if ((it -> second) > maxx) {
			maxx = it -> second;
			ans = it -> first;
		}
	}
	cout << ans << endl;
	return 0;
}
