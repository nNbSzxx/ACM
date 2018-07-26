#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[30];
	while (~scanf("%s",s)) {
		int len = strlen(s);
		int cnt = 0;
		if (len == 1) {
			puts("YES");
			continue;
		}
		for (int i = 0; i < len / 2; i ++) {
			if (s[i] != s[len - 1 - i]) {
				cnt ++;
			}
		}
		if (cnt == 1 || cnt == 0 && len % 2 == 1) {
			printf("YES\n");
		} else {
			puts("NO");
		}
	}
	return 0;
}
