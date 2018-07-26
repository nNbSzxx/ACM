#include <stdio.h>
#include <string.h>

int main()
{
	char s[100005];
	int n;
	char sp[] = {'0','a','e','i','o','u','y'};
	while (~scanf("%d %s",&n,s)) {
		int len = strlen(s);
		int prekind = 0;
		int cnt = 0, flag = 1;
		for (int i = 0; i < len; i ++) {
			flag = 1;
			if ((prekind == 2 || prekind == 4) && s[i] != sp[prekind]) {
				if (cnt <= 2) {
					for (int j = 1; j <= cnt; j ++)
						printf("%c",sp[prekind]);
				} else {
					printf("%c",sp[prekind]);
				}
			}
			switch (s[i]) {
				case 'a':
					if (prekind == 1) flag = 0,cnt++;
					else prekind = cnt = 1;
					break;
				case 'e':
					if (prekind == 2) {
						cnt ++;
					} else prekind = 2, cnt=1;
					flag = 0;
					break;
				case 'i':
					if (prekind == 3) flag = 0,cnt++;
					else prekind = 3,cnt = 1;
					break;
				case 'o':
					if (prekind == 4 ) {
						cnt ++;
					} else prekind = 4, cnt=1;
					flag = 0;
					break;
				case 'u':
					if (prekind == 5) flag = 0,cnt++;
					else prekind = 5,cnt = 1;
					break;
				case 'y':
					if (prekind == 6) flag = 0,cnt++;
					else prekind = 6,cnt = 1;
					break;
				default : cnt = 0, prekind = 0;
			}
			if (flag) printf("%c",s[i]);
		}
		printf("\n");
	}
	
	return 0;
}
