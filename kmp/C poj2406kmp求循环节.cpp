#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[1000010];
	int nt[1000010];
	while (scanf("%s",s), strcmp(s,".")) {
		nt[0] = -1;
		int len = strlen(s);
		int i = 0, j = -1;
		while  ( i < len) {
			if (j == -1 || s[i] == s[j]) {
				nt[++ i] = ++ j;
			} else {
				j = nt[j];
			}
		}
		if (len % (len - nt[len]) == 0 ) {
			printf("%d\n",len / (len - nt[len]));
		} else {
			puts("1");
		}
	}
}
