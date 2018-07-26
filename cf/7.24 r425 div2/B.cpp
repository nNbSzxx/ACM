#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
	string g, p;
	cin >> g >> p;
	set<char> st;
	for (int i = 0; i < g.size(); i ++) {
		st.insert(g[i]);
	}
	int star = 0;
	for (int i = 0; i < p.size(); i ++) {
		if (p[i] == '*') {
			star = 1;
			break;
		}
	}
	int n;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i ++) {
		cin >> s;
		if (p.size() != s.size()) {
			if (!star) {
				cout << "NO" << endl;
				continue;
			}
			if (p.size() - 1 > s.size()) {
				cout << "NO" << endl;
				continue;
			}
		}
		int j = 0;
		int k = 0; 
		int f = 1;
		for ( ; j < p.size() && k < s.size(); )  {
			if (p[j] == '?') {
				int flag = 0;
				for (int ii = 0; ii < g.size(); ii ++) {
					if (g[ii] == s[k]) {
						flag = 1;
						break;
					}
				}
				if (!flag) {
					f = 0;
					cout << "NO" << endl;
					break;
				}
				++ j;
				++ k;
			} else if (p[j] == '*') {
				int len = s.size() - p.size() + 1;
				int flag = 1;
				for (int ii = 0; ii < len; ii ++) {
					if (st.count(s[k + ii])) {
						flag = 0;
						break;
					}
				}
				if (!flag) {
					f = 0;
					cout << "NO" << endl;
					break;
				}
				++ j;
				k += len;
				
				continue;
			} else {
				if (s[k] != p[j]) {
					f = 0;
					cout << "NO" << endl;
					break;
				}
				++ j;
				++ k;
			}
		}
		if (f) {
			cout << "YES" << endl;
		}
	}
	
	return 0;
}
