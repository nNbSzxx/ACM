#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int len;
string s;

int main()
{
	cin >> len;
	cin >> s;
	int i = 0;
	//while (i < len && s[i] >= 'a' && s[i] <= 'z') i ++;
	//++ i;
	int maxx = 0, cnt = 0, vis[26];
	memset(vis, 0, sizeof vis);
	for (; i < len; i ++) {
		if (s[i] <= 'z' && s[i] >= 'a' ) {
			if (!vis[s[i] - 'a'])
				++ cnt, vis[s[i] - 'a'] = 1;
		} else {
			maxx = max(maxx, cnt);
			cnt = 0;
			memset(vis, 0, sizeof vis);
		}
	}
	maxx = max(maxx, cnt);
	printf("%d\n", maxx);
}
