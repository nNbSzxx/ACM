#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int cs = 0, cf = 0;
	char cur = s[0];
	for (int i = 1; i < n; i ++) {
		if (cur != s[i]) {
			if (s[i] == 'S') {
				cs ++; 
			} else {
				cf ++;
			}
			cur = s[i];
		}
	}
	if (cf > cs) {
		puts("YES");
	} else {
		puts("NO");
	}
	
	return 0;
}
