#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	int n, k;
	cin >> n >> k;
	cin >> s;
	int cnt[30];
	memset(cnt, 0, sizeof(cnt));
	int maxx = -1;
	for (int i = 0; i < s.size(); i ++) {
		cnt[s[i] - 'a'] ++;
		maxx = max(maxx, cnt[s[i] - 'a']);
	}
	if (maxx > k) {
		puts("NO");
	} else {
		puts("YES");
	}
} 
