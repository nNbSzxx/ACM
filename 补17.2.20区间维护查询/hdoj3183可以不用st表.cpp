#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1005;

int main()
{
	char s[MAX], ans[MAX];
	int m;
	while (~scanf(" %s%d",s,&m)) {
		int len = strlen(s);
		int flag = 0;
		int loc = 1;
		int temp = 0;
		for (int i = 1; i <= len - m; i ++) {
			int minn = '9' + 1;
			for (int j = temp; j <= m + i - 1; j ++) {
				if (minn > s[j]) {
					minn = s[j];
					temp = j + 1;
				}
			}
			if (minn != '0' && !flag) {
				flag = 1;
				loc = i;
			}
			ans[i] = minn;
		}
		if (!flag) {
			printf("0\n");
			continue;
		}
		for (int i = loc; i <= len - m; i ++) {
			printf("%c",ans[i]);
		}
		printf("\n");
	}
}
