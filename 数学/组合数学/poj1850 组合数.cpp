#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s[50];
	int c[30][30];
	for (int i = 1; i <= 26; i ++) {
		for (int  j = 0; j <= i; j ++) {
			if (j == 0 || j == i) {
				c[i][j] = 1;
			} else {
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			}
		}
	}
	while (~scanf(" %s",s)) {
		int len = strlen(s);
		int ans = 0;
		int flag = 0;
		for (int i = 1; i < len; i ++) {
			if (s[i] <= s[i - 1]) {
				puts("0");
				flag = 1;
				break;
			}
		}
		if (flag) {
			continue;
		}
		for (int i = 1; i < len; i ++) {
			ans += c[26][i];
		}
		for (int i = 0; i < len; i ++) {
			char j;
			if (i == 0) {
				j = 'a';
			} else {
				j = s[i - 1] + 1;
			}
			while (j <= s[i] - 1) {
				ans += c['z' - j][len - 1 - i];
				++ j;
			}
		}
		printf("%d\n",ans + 1);
	}
	return 0;
}






