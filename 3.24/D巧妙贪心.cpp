#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() 
{
	int n,m;
	string s[60];
	string ans[60];
	for (int i = 1; i <= 50; i ++) {
		s[i] += 'A' + (i-1) % 26;
	}
	for (int i = 1; i <= 26; i ++) {
		s[i] += 'a' + i - 1;
	}
	for (int i = 27; i <= 50; i ++) {
		s[i] += 'a' + i - 26;
	}
//	for (int i = 1; i <= 50; i ++) {
//		s[i][2] = '\0';
//	}
	while (~scanf("%d%d",&n,&m)) {
		int p = 2;
		ans[1] = s[1];
		for (int i = 2; i <= m - 1; i ++)
			ans[i] = s[p ++];
		char s1[10];
		for (int i = m; i <= n; i ++) {
			scanf("%s",s1);
			if (!strcmp(s1,"YES")) {
				ans[i] = s[p ++];
			} else {
				ans[i] = ans[i - m + 1];
				p ++;
			}
		}
		cout << ans[1];
		for (int i = 2; i <= n; i ++) {
			cout << " " << ans[i];
		}
		printf("\n");
	}
	
	return 0;
} 
